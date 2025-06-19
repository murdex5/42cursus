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
int	only_one(t_data *data, t_philo *philo)
{
	if (data->num_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		log_action(data, philo->id, "has taken a fork");
		usleep(data->time_to_die * 1000);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	return (0);
}

void	set_forks(t_philo *philo, pthread_mutex_t **first_fork_to_pick,
		pthread_mutex_t **second_fork_to_pick)
{
	*first_fork_to_pick = philo->right_fork;
	*second_fork_to_pick = philo->left_fork;
	if (if_odd(philo->id))
	{
		*first_fork_to_pick = philo->left_fork;
		*second_fork_to_pick = philo->right_fork;
	}
}


void	update_meals(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->write_mutex);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&data->write_mutex);
}
