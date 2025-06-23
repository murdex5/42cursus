/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:12:26 by kadferna          #+#    #+#             */
/*   Updated: 2025/06/23 13:12:30 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_philos(t_data *data, t_philo **philos, int *all_philos_have_eaten)
{
	int		i;
	long	time_since_last_meal;
	int		philo_meals_eaten;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->meal_mutex);
		time_since_last_meal = get_time() - (*philos)[i].last_meal_time;
		philo_meals_eaten = (*philos)[i].meals_eaten;
		pthread_mutex_unlock(&data->meal_mutex);
		if (check_death_flag(data, philos, time_since_last_meal, i) == 0)
			return (0);
		if (data->max_meals != -1 && philo_meals_eaten < data->max_meals)
			*all_philos_have_eaten = 0;
		i++;
		usleep(100);
	}
	return (1);
}
