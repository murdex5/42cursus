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

int	pick_forks(t_data *data, t_philo *philo,
		pthread_mutex_t *first_fork_to_pick,
		pthread_mutex_t *second_fork_to_pick)
{
	if (check_death(data))
		return (0);
	log_action(data, philo->id, "is thinking");
	if (check_death(data))
		return (0);
	pthread_mutex_lock(first_fork_to_pick);
	log_action(data, philo->id, "has taken a fork");
	if (check_death(data))
	{
		pthread_mutex_unlock(first_fork_to_pick);
		return (0);
	}
	pthread_mutex_lock(second_fork_to_pick);
	log_action(data, philo->id, "has taken a fork");
	if (check_death(data))
	{
		pthread_mutex_unlock(first_fork_to_pick);
		pthread_mutex_unlock(second_fork_to_pick);
		return (0);
	}
	return (1);
}
void	update_meals(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->death_mutex);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&data->death_mutex);
}

int	check_death_loop(time_t current_time, t_philo **philos, t_data *data,
		bool *all_philos_eaten)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
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
	}
	return (1);
}
