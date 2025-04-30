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
	str = malloc(sizeof(char *) * (argc ));
	if (!str)
		return (str);
	while (i < argc)
	{
		str[i - 1] = ft_strdup(argv[i]);
		if (!str[i - 1])
			return (free_str_list(str), NULL);
		i++;
	}
	str[argc-1] = NULL;
	(*len) = argc - 1;
	return (str);
}
