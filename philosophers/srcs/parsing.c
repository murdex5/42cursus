/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:53:05 by kadferna          #+#    #+#             */
/*   Updated: 2025/05/14 13:53:06 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_data	*init_data(int *nums)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->philo_num = nums[0];
	data->death_time = nums[1];
	data->eat_time = nums[2];
	data->sleep_time = nums[3];
	data->meals_nb = nums[4];
	data->dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	return (data);
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].time_to_die = data->death_time;
		data->philos[i].eat_cont = 0;
		data->philos[i].eating = 0;
		data->philos[i].status = 0;
		pthread_mutex_init(&data->philos[i].lock, NULL);
		i++;
	}
}

int	init_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	data->philos[0].l_fork = &data->forks[0];
	data->philos[0].r_fork = &data->forks[data->philo_num - 1];
	i = 1;
	while (i < data->philo_num)
	{
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[i - 1];
		i++;
	}
	return (1);
}

int	get_mem(t_data *data)
{
	data->tid = malloc(sizeof(pthread_t) * data->philo_num);
	if (!data->tid)
		return (std_error("Memory allocation for tid failed"), 0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->forks)
	{
		free(data->tid);
		return (std_error("Memory allocation for forks failed"), 0);
	}
	data->philos = malloc(sizeof(t_philo) * data->philo_num);
	if (!data->philos)
	{
		free(data->tid);
		free(data->forks);
		return (std_error("Memory allocation for philosopers failed"), 0);
	}
	return (1);
}

t_data	*init(int *nums)
{
	t_data	*data;

	data = init_data(nums);
	if (!data)
		return (NULL);
	if (!get_mem(data))
	{
		free(data);
		return (NULL);
	}
	if (!init_forks(data))
	{
		free(data->tid);
		free(data->forks);
		free(data->philos);
		free(data);
		return (NULL);
	}
	init_philos(data);
	return (data);
}
