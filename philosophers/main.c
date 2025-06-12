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
	t_data			*data;
	pthread_mutex_t	*first_fork_to_pick;
	pthread_mutex_t	*second_fork_to_pick;

	philo = (t_philo *)arg;
	data = philo->data;
	if (data->num_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		log_action(data, philo->id, "has taken the fork");
		usleep(data->time_to_die * 1000);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}
	first_fork_to_pick = philo->right_fork;
	second_fork_to_pick = philo->left_fork;
	if (if_odd(philo->id) == true)
	{
		first_fork_to_pick = philo->left_fork;
		second_fork_to_pick = philo->right_fork;
	}
	while (1)
	{
		pthread_mutex_lock(&data->death_mutex);
		if (data->death_flag == true)
		{
			pthread_mutex_unlock(&data->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->death_mutex);
		log_action(data, philo->id, "is thinking");
		pthread_mutex_lock(first_fork_to_pick);
		log_action(data, philo->id, "has taken a fork");
		pthread_mutex_lock(&data->death_mutex);
		if (data->death_flag == true)
		{
			pthread_mutex_unlock(&data->death_mutex);
			pthread_mutex_unlock(first_fork_to_pick);
			break ;
		}
		pthread_mutex_unlock(&data->death_mutex);
		pthread_mutex_lock(second_fork_to_pick);
		log_action(data, philo->id, "has taken a fork");
		log_action(data, philo->id, "is eating");
		pthread_mutex_lock(&data->death_mutex);
		philo->last_meal_time = get_time();
		philo->meals_eaten++;
		pthread_mutex_unlock(&data->death_mutex);
		usleep(data->time_to_eat * 1000);
		pthread_mutex_unlock(first_fork_to_pick);
		pthread_mutex_unlock(second_fork_to_pick);
		usleep(data->time_to_sleep * 1000);
		log_action(data, philo->id, "is sleeping");
	}
	return (NULL);
}

void	monitor(t_philo **philos, t_data *data)
{
	bool	all_philos_eaten;
	long	current_time;
	int		i;

	all_philos_eaten = false;
	while (1)
	{
		i = -1;
		all_philos_eaten = true;
		current_time = get_time();
		while (++i < data->num_philos)
		{
			pthread_mutex_lock(&data->death_mutex);
			if ((current_time - (*philos)[i].last_meal_time) > data->time_to_die
				&& !data->death_flag)
			{
				data->death_flag = true;
				pthread_mutex_unlock(&data->death_mutex);
				log_action(data, (*philos)[i].id, "has died");
				return ;
			}
			if (data->max_meals != 1
				&& data->max_meals > (*philos)[i].meals_eaten)
				all_philos_eaten = false;
			if (data->death_flag == true)
			{
				pthread_mutex_unlock(&data->death_mutex);
				goto end_monitor_loop;
			}
			pthread_mutex_unlock(&data->death_mutex);
		}
		if (data->max_meals != -1 && all_philos_eaten == true)
		{
			pthread_mutex_lock(&data->death_mutex);
			if (data->death_flag == false)
				data->death_flag = true;
			pthread_mutex_unlock(&data->death_mutex);
			goto end_monitor_loop;
		}
		usleep(1000);
	}
end_monitor_loop:
	return ;
}

int	main(int argc, char **argv)
{
	int		nums[argc - 1];
	t_data	*data;
	t_philo *_philo_array_head;
	t_philo	**philos;
	int		i;

	i = -1;

	_philo_array_head = NULL;
	philos = &_philo_array_head;
	if (!checks(nums, argc, argv))
		return (1);
	if (!check_num_values(nums))
		return (1);
	data = init(nums, philos);
	if (!data)
		return (1);
	if (!philos || !*philos)
		return (free_data_struct(data, NULL), 1);
	while (++i < data->num_philos)
		pthread_create(&(*philos)[i].thread, NULL, routine, &(*philos)[i]);
	monitor(philos, data);
	i = -1;
	while (++i < data->num_philos)
		pthread_join((*philos)[i].thread, NULL);
	if (data)
		free_data_struct(data, philos);
	return (0);
}
