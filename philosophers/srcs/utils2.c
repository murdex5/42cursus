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

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->write_mutex);
	if (!philo->data->death_flag)
		printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id,
			status);
	pthread_mutex_unlock(&philo->data->write_mutex);
}
