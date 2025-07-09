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

int	check_philos(t_data *data, t_philo *philos, int *all_philos_have_eaten)
{
	int		i;
	long	time_since_last_meal;
	int		philo_meals_eaten;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->meal_mutex);
		time_since_last_meal = get_time() - philos[i].last_meal_time;
		if (time_since_last_meal > data->time_to_die - 10)
		{
			pthread_mutex_unlock(&data->meal_mutex);
			usleep(50);
			continue ;
		}
		philo_meals_eaten = philos[i].meals_eaten;
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

int	create_philos_routine(t_philo *philos, void *routine(void *), int i)
{
	if (pthread_create(&philos[i].thread, NULL, routine, &philos[i]) != 0)
		return (0);
	return (1);
}

t_data	*check_init(int argc, char **argv, int *nums, t_philo *philos)
{
	t_data	*data;

	if (!checks(nums, argc, argv))
		return (NULL);
	data = init(nums, &philos);
	if (!data)
		return (NULL);
	return (data);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	if (n == 0)
		return (s);
	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
