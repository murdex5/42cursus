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
	if (only_one(data, philo))
		return (NULL);
	set_forks(philo, &first_fork_to_pick, &second_fork_to_pick);
	while (1)
	{
		if (!pick_forks(data, philo, first_fork_to_pick, second_fork_to_pick))
			return (NULL);
		update_meals(data, philo);
		log_action(data, philo->id, "is eating");
		ft_usleep(data->time_to_eat, data);
		pthread_mutex_unlock(first_fork_to_pick);
		pthread_mutex_unlock(second_fork_to_pick);
		if (check_death(data))
			return (NULL);
		log_action(data, philo->id, "is sleeping");
		ft_usleep(data->time_to_sleep, data);
	}
	return (NULL);
}

void	monitor(t_philo **philos, t_data *data)
{
	bool	all_philos_eaten;
	long	current_time;

	while (1)
	{
		all_philos_eaten = true;
		current_time = get_time();
		if (!check_death_loop(current_time, philos, data, &all_philos_eaten))
			return ;
		if (data->max_meals != -1 && all_philos_eaten)
		{
			pthread_mutex_lock(&data->death_mutex);
			if (!data->death_flag)
				data->death_flag = true;
			pthread_mutex_unlock(&data->death_mutex);
			return ;
		}
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int		nums[argc - 1];
	t_data	*data;
	t_philo	*_philo_array_head;
	t_philo	**philos;
	int		i;

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
		pthread_create(&(*philos)[i].thread, NULL, routine, &(*philos)[i]);
	monitor(philos, data);
	i = -1;
	while (++i < data->num_philos)
		pthread_join((*philos)[i].thread, NULL);
	if (data)
		free_data_struct(data, philos);
	return (0);
}
