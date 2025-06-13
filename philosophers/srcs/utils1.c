/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:32:51 by kadferna          #+#    #+#             */
/*   Updated: 2025/05/16 13:32:55 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

time_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
	{
		std_error("gettimeofday failed");
		return ((time_t)0);
	}
	return ((tv.tv_sec * (time_t)1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(time_t milliseconds, t_data *data)
{
	time_t	start;

	start = get_time();
	while (get_time() - start < milliseconds)
	{
		usleep(100);
		pthread_mutex_lock(&data->death_mutex);
		if (data->death_flag)
		{
			pthread_mutex_unlock(&data->death_mutex);
			return ;
		}
		pthread_mutex_unlock(&data->death_mutex);
	}
	return ;
}
