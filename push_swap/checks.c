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

static int	check_params(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

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

static int	check_doubles(int *arr, int len)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		temp = arr[i];
		while (j < len)
		{
			if (temp == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


int *checks(int argc, char **argv, int *len)
{
	int *ints;

	if (!check_params(argc, argv))
		return (NULL);
	ints = get_ints(argc, argv, len);
	if (!ints)
		return (NULL);
	if (!check_doubles(ints, len))
		return(NULL);
	return (ints);
}
