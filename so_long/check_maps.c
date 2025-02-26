/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
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
		return (0);
	if (ft_strlen(dot) != ft_strlen(type))
		return (0);
	if (ft_strncmp(dot, type, ft_strlen(type)) == 0)
		return (1);
	else
		return (0);
}

int	if_map_rectangled(t_map *map)
{
	int first_line_lentgh;
	int i;

	if (!map || !map->content || !map->content[0])
		return (0);
	first_line_lentgh = ft_strlen(map->content[0]);
	i = 0;
	while (i < map->height)
	{
		if ((int)ft_strlen(map->content[i]) != first_line_lentgh)
			return (0);
		i++;
	}
	map->width = first_line_lentgh;
	return (1);
}

int if_map_sorrounded(t_map map)
{
    
}

int	error_message(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}