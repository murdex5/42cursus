/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:22:57 by kadferna          #+#    #+#             */
/*   Updated: 2025/06/12 12:23:32 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	if_odd(int n)
{
	if (n % 2 == 0)
		return (false);
	else
		return (true);
}

void	log_action(t_data *data, int philo_id, char *msg)
{
	long	timestamp;

	pthread_mutex_lock(&data->write_mutex);
	timestamp = get_time() - data->start_time;
	printf("%ld %d %s\n", timestamp, philo_id, msg);
	pthread_mutex_unlock(&data->write_mutex);
}

bool	check_death(t_data *data)
{
	bool	ret;

	pthread_mutex_lock(&data->death_mutex);
	ret = data->death_flag;
	pthread_mutex_unlock(&data->death_mutex);
	return (ret);
}

int	check_death_loop(time_t current_time, t_philo **philos,
		bool *all_philos_eaten, int i)
{
	t_data	*data;

	data = (*philos)[i].data;
	pthread_mutex_lock(&data->death_mutex);
	if ((current_time - (*philos)[i].last_meal_time) > data->time_to_die
		&& !data->death_flag)
	{
		data->death_flag = true;
		log_action(data, (*philos)[i].id, "died");
		pthread_mutex_unlock(&data->death_mutex);
		return (0);
	}
	if (data->max_meals != -1 && (*philos)[i].meals_eaten < data->max_meals)
		*all_philos_eaten = false;
	if (data->death_flag)
	{
		pthread_mutex_unlock(&data->death_mutex);
		return (0);
	}
	pthread_mutex_unlock(&data->death_mutex);
	return (1);
}
