/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:46:33 by kadferna          #+#    #+#             */
/*   Updated: 2025/02/20 11:46:34 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	check_file_type(char *file, char *type)
{
	char *dot;

	dot = ft_strchr(file, '.');
	if (!dot)
		return (1);
	if (ft_strlen(dot) != ft_strlen(type))
		return (1);
	if (ft_strncmp(dot, type, ft_strlen(type)) == 0)
		return (0);
	else
		return (1);
}

int	check_map(int argc, char **argv)
{
	int i;
	char *file;

	if (argc != 2)
		return (1);
	file = argv[1];
	i = check_file_type(file, ".ber");
	if (i)
	{
		ft_printf("Wrong file type!\n");
		return (1);
	}
	return (0);
}
