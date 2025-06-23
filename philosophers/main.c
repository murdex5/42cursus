/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:01:13 by kadferna          #+#    #+#             */
/*   Updated: 2025/05/09 12:01:35 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo			*philo;
	pthread_mutex_t	*first_fork_pick;
	pthread_mutex_t	*second_fork_pick;

	philo = (t_philo *)arg;
	first_fork_pick = philo->left_fork;
	second_fork_pick = philo->right_fork;
	if (philo->id % 2 == 0)
	{
		first_fork_pick = philo->right_fork;
		second_fork_pick = philo->left_fork;
	}
	while (1)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		if (philo->data->death_flag)
		{
			pthread_mutex_unlock(&philo->data->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->death_mutex);
		pthread_mutex_lock(first_fork_pick);
		print_status(philo, "has taken a fork");
		if (philo->data->num_philos == 1)
		{
			usleep(philo->data->time_to_die * 1000);
			pthread_mutex_unlock(philo->left_fork);
			break ;
		}
		pthread_mutex_lock(second_fork_pick);
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		pthread_mutex_lock(&philo->data->meal_mutex);
		philo->last_meal_time = get_time();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->data->meal_mutex);
		usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		print_status(philo, "is sleeping");
		usleep(philo->data->time_to_sleep * 1000);
		print_status(philo, "is thinking");
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_data	*data;
	t_philo	**philos;
	int		i;
	int		all_philos_have_eaten;
	long	time_since_last_meal;
	int		philo_meals_eaten;

	philos = (t_philo **)arg;
	data = philos[0]->data;
	while (1)
	{
		all_philos_have_eaten = 1;
		for (i = 0; i < data->num_philos; i++)
		{
			pthread_mutex_lock(&data->meal_mutex);
			time_since_last_meal = get_time() - (*philos)[i].last_meal_time;
			philo_meals_eaten = (*philos)[i].meals_eaten;
			pthread_mutex_unlock(&data->meal_mutex);
			if (time_since_last_meal > data->time_to_die)
			{
				pthread_mutex_lock(&data->death_mutex);
				if (!data->death_flag)
				{
					data->death_flag = true;
					pthread_mutex_lock(&data->write_mutex);
					printf("%ld %d died\n", get_time() - data->start_time,
						(*philos)[i].id);
					pthread_mutex_unlock(&data->write_mutex);
				}
				pthread_mutex_unlock(&data->death_mutex);
				return (NULL);
			}
			if (data->max_meals != -1 && philo_meals_eaten < data->max_meals)
				all_philos_have_eaten = 0;
			usleep(100);
		}
		if (data->max_meals != -1 && all_philos_have_eaten)
		{
			pthread_mutex_lock(&data->death_mutex);
			data->death_flag = true;
			pthread_mutex_unlock(&data->death_mutex);
			return (NULL);
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int			nums[argc - 1];
	t_data		*data;
	t_philo		*_philo_array_head;
	t_philo		**philos;
	int			i;
	pthread_t	monitor_thread;

	i = -1;
	_philo_array_head = NULL;
	philos = &_philo_array_head;
	if (!checks(nums, argc, argv))
		return (1);
	data = init(nums, philos);
	if (!data)
		return (1);
	if (!philos || !*philos)
		return (free_data_struct(data, NULL), 1);
	while (++i < data->num_philos)
	{
		if (pthread_create(&(*philos)[i].thread, NULL, routine,
				&(*philos)[i]) != 0)
			return (1);
	}
	pthread_create(&monitor_thread, NULL, monitor, philos);
	i = -1;
	while (++i < data->num_philos)
		pthread_join((*philos)[i].thread, NULL);
	pthread_join(monitor_thread, NULL);
	if (data)
		free_data_struct(data, philos);
	return (0);
}
