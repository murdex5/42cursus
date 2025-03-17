/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:46:39 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/17 10:46:40 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_ints(int argc, char **argv)
{
	int	*ints;
	int	i;

	ints = malloc(sizeof(int) * (argc - 1));
	if (!ints)
		return (NULL);
	i = 0;
	while (i < (argc - 1))
	{
		ints[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (ints);
}

int	check_params(int argc, char **argv)
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
			if (!(argv[i][k] >= '0' && argv[i][k] <= '9'))
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int	error_msg(void)
{
	ft_putstr_fd("Error", 2);
	ft_putstr_fd("\n", 2);
	return (0);
}