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

u_int64_t get_time(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		return (std_error("gettimeofdat failed\n"), 0);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_sec / 1000));
}

int ft_usleep(__useconds_t time)
{
	u_int64_t start;
	u_int64_t current_time;

	start = get_time();
	current_time = get_time();
	while (current_time - start < time)
	{
		current_time = get_time();
		usleep(time / 10);
	}
	return (0);

}
