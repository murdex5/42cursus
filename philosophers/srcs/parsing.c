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
	data->num_philos = nums[0];
	data->time_to_die = nums[1];
	data->time_to_eat = nums[2];
	data->time_to_sleep = nums[3];
	data->max_meals = nums[4];
	data->forks = NULL;
	data->death_flag = false;
	data->start_time = get_time();
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
	{
		free(data);
		return (NULL);
	}
	if (pthread_mutex_init(&data->write_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->death_mutex);
		free(data);
		return (NULL);
	}
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
		(*philos)[i].id = i + 1;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].last_meal_time = get_time();
		(*philos)[i].data = data;
		(*philos)[i].left_fork = NULL;
		(*philos)[i].right_fork = NULL;
	}
	return (1);
}

int	init_forks(t_data *data, t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			return (0);
		}
	}
	i = -1;
	while (++i < data->num_philos)
	{
		(*philos)[i].left_fork = &data->forks[i];
		(*philos)[i].right_fork = &data->forks[(i + 1) % data->num_philos];
	}
	return (1);
}

t_data	*init(int *nums, t_philo **philos)
{
	t_data	*data;

	data = init_data(nums);
	if (!data)
		return (std_error("Initializing data failed"), NULL);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
	{
		pthread_mutex_destroy(&data->death_mutex);
		pthread_mutex_destroy(&data->write_mutex);
		free(data);
		return (std_error("could not allocate memory for Forks"), NULL);
	}
	if (!init_philos(data, philos))
	{
		destroy_mutex(data);
		return (std_error("Initializing philosophers failed"), NULL);
	}
	if (!init_forks(data, philos))
	{
		free_philos(philos);
		destroy_mutex(data);
		return (std_error("Initializing forks failed"), NULL);
	}
	return (data);
}
