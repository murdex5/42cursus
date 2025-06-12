/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:52:20 by kadferna          #+#    #+#             */
/*   Updated: 2025/05/16 14:52:35 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"



void	free_data_struct(t_data *data)
{
	int	i;

	if (!data)
		return ;
	i = -1;
	while (++i < data->num_philos)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->death_mutex);
	pthread_mutex_destroy(&data->write_mutex);
	free(data);
}
