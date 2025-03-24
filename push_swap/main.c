/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:46:26 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/17 12:25:52 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	**ints;
	int **a;
	int len;

	if (argc < 2)
		return (error_msg(), 1);
	ints = checks(argc, argv, &len);
	if (!ints)
		return (error_msg(), 1);
	int i = 0;
	pa(a, ints, 0, &len);
	while (i < len)
	{
		ft_printf("%d\n", *ints[i]);
		i++;
	}
	ft_printf("sucesss!!\n");
	return (0);
}
