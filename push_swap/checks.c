/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:55:09 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/20 13:55:25 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_params(int argc, char **argv)
{
	int i;
	int j;
	int k;

	i = 1;
	while (i < argc)
	{
		j = ft_strlen(argv[i]);
		k = 0;
		while (k < j)
		{
			if ((argv[i][k] >= 'a' && argv[i][k] <= 'z'))
				return (0);
			if ((argv[i][k] >= 'A' && argv[i][k] <= 'Z'))
                return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int check_doubles(int *arr, int len)
{
	int temp;
	int i = 0;
	int j;
	while (i < len)
	{
		j = i + 1;
		temp = arr[i];
	}
}