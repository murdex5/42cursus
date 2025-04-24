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

#include "../push_swap.h"

static int	free_str_int(int **ints, char **str, int len)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	while (len > 0)
	{
		free(ints[len]);
		len--;
	}
	while (i > 0)
		free(str[--i]);
	free(str);
	free(ints);
	return (1);
}

static int	**int_arr(char **argv, int *len)
{
	char	**str;
	int		i;
	int		**nums;

	i = 0;
	str = ft_split(argv[1], ' ');
	if (!str)
		return (NULL);
	(*len) = get_items(argv[1], ' ');
	nums = malloc(sizeof(int *) * (*len));
	if (!nums)
		return (NULL);
	while (i < (*len))
	{
		nums[i] = malloc(sizeof(int));
		if (!nums[i])
			return (free_str_int(nums, str, i), NULL);
		*nums[i] = ft_atoi(str[i]);
		i++;
	}
	while (i > 0)
		free(str[--i]);
	free(str);
	i = 0;
	return (nums);
}

// if (argv[i + 1] == "2147483647" || argv[i + 1] == "-2147483648")
// 			return (NULL);

int	**get_ints(int argc, char **argv, int *len)
{
	int	**ints;
	int	i;

	if (argc == 2)
		return (int_arr(argv, len));
	i = 0;
	ints = malloc(sizeof(int *) * (argc - 1));
	if (!ints)
		return (NULL);
	while (i < argc - 1)
	{
		ints[i] = malloc(sizeof(int));
		if (ft_strncmp(argv[i + 1], "2147483647", ft_strlen(argv[i + 1])) == 0
			|| ft_strncmp(argv[i + 1], "-2147483648", ft_strlen(argv[i + 1])) == 0)
			return (free_list(ints, i), NULL);
		if (!ints[i])
			return (free_list(ints, i), NULL);
		*ints[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	*len = argc - 1;
	return (ints);
}
