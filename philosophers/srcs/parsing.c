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

void init_forks(t_data *data)
{
	int i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

t_data	*init_data(int *nums)
{
	t_data	*data;
	data = malloc(sizeof(t_data) * 1);
	if(!data)
		return (NULL);
	data->num_philos = nums[0];
	data->time_to_die = nums[1];
	data->time_to_eat = nums[2];
	data->time_to_sleep = nums[3];
	data->max_meals = nums[4];
	if (pthread_mutex_init(&death_mutex) != 0)
		return ("Failed to initialize death mutex", NULL);
	if (pthread_mutex_init(&write_mutex) != 0)
		return ("Failed to initialize write mutex", NULL)
	return (data);
}

int	init_philos(t_data *data, t_philo **philos)
{
	int	i;
	if (!data)
		return (0);

	*philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!*philos)
		return (0);

	i = -1;
	while (++i < data->num_philos)
	{
		(*philos)[i].id = i+1;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].last_meal_time = get_time();
		(*philos)[i].data = data;
		(*philos)[i].left_fork = &data->forks[i];
		(*philos)[i].right_fork = &data->forks[(i + 1) % data->num_philos];
	}
	return (1);
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

int	*init(int *nums, t_data *data, t_philo **philos)
{
	data = init_data(nums);
	if (!data)
		return ("Inisializing data failed", 0);
	if (!init_forks(data))
		return ("Inisizlizing forks failed", 0);
	if (!init_philos(data, philos))
		return ("Initializing philosophers failed", 0);
	return (1);
}
