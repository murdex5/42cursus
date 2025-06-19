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
	t_philo *philo;
	t_data *data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (data->num_philos == 1)
	{
		
	}
	return (NULL);
}

void	*monitor(void *arg)
{
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
