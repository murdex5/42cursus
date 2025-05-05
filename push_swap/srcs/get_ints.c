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

static int	check_if_ints(char *str)
{
	int	i;

	i = 0;
	if (!check_spaces(str))
		return (0);
	while (str[i] != '\0')
	{
		if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0'
					&& str[i] <= '9')))
			return (0);
		if (i > 0 && str[i] == '-' && str[i - 1] != '-')
			return (0);
		if ((str[i] == '+' || str[i] == '-') && str[i] == '0')
			return (0);
		i++;
	}
	return (1);
}

char	**get_ints(int argc, char **argv, int *len)
{
	char	**str;
	int		i;

	i = 1;
	if (argc < 2)
		return (error_msg(), NULL);
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		(*len) = argc - 1;
		return (str);
	}
	str = malloc_and_set_null(argc);
	if (!str)
		return (str);
	while (i < argc)
	{
		str[i - 1] = ft_strdup(argv[i]);
		if (!str[i - 1])
			return (free_str_list(str), NULL);
		i++;
	}
	str[argc - 1] = NULL;
	(*len) = argc - 1;
	return (str);
}

char	**get_int_checks(int argc, char **argv, int *len)
{
	char	**str;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!check_if_ints(argv[i]))
			return (0);
		i++;
	}
	str = get_ints(argc, argv, len);
	if (!str)
		return (NULL);
	return (str);
}
