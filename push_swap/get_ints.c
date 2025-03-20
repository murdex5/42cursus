/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ints.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:04:11 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/20 14:06:36 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*int_arr(char **argv, int *len)
{
	char	**str;
	int		i;
	int		*nums;

	i = 0;
	str = ft_split(argv[1], ' ');
	if (!str)
		return (NULL);
    (*len) = get_items(argv[1], ' ');
	nums = malloc(sizeof(int) * (*len));
	if (!nums)
		return (NULL);
	while (i <  (*len))
	{
		nums[i] = ft_atoi(str[i]);
		i++;
	}
	while (i > 0)
		free(str[--i]);
	free(str);
	i = 0;
	return (nums);
}

int	*get_ints(int argc, char **argv, int *len)
{
	int *ints;
	int i;

	if (argc == 2)
		return (int_arr(argv, len));
	ints = malloc(sizeof(int) * (argc - 1));
	if (!ints)
		return (NULL);
	i = 0;
	while (i < (argc - 1))
	{
		ints[i] = ft_atoi(argv[i + 1]);
		i++;
	}
    i =  (*len);
	return (ints);
}