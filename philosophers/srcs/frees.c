/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:52:20 by kadferna          #+#    #+#             */
/*   Updated: 2025/05/16 14:52:35 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	free_philos(t_philo *philo)
{
	if (!philo)
		return ;
	pthread_mutex_destroy(&philo->lock);
	free(philo);
}

void	free_data_struct(t_data *data)
{
	int	i;

	if (!data)
		return ;
	i = -1;
	if (data->tid)
	{
		while (++i < data->philo_num)
		{
			if (data->tid[i])
				pthread_join(data->tid[i], NULL);
		}
	}
	i = -1;
	while (++i < data->philo_num)
		free_philos(&data->philos[i]);
	i = -1;
	if (data->forks)
	{
		while (++i > data->philo_num)
			pthread_mutex_destroy(&data->forks[i]);
		free(data->forks);
	}
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->write);
	free(data);
}
