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
	long timestamp;
	pthread_mutex_lock(&data->write_mutex);
	timestamp = get_time() - data->start_time;
	printf("%ld %d %s", timestamp, philo_id, msg);
	pthread_mutex_unlock(&data->write_mutex);
}