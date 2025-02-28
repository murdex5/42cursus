/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:45:09 by kadferna          #+#    #+#             */
/*   Updated: 2025/02/27 15:45:13 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file_type(char *file, char *type)
{
	char *dot;

	dot = ft_strchr(file, '.');
	if (!dot)
		return (0);
	if (ft_strlen(dot) != ft_strlen(type))
		return (0);
	if (ft_strncmp(dot, type, ft_strlen(type)) == 0)
		return (1);
	else
		return (0);
}