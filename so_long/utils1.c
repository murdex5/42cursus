/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:48:57 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/06 11:48:59 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	alloc_mem(t_map *map, int line_count)
{
	if (!map)
		return (0);
	map->content = malloc(sizeof(char *) * (line_count + 1));
	if (!map->content)
	{
		free(map);
		return (0);
	}
	map->content[line_count] = NULL;
	return (1);
}

int	flood_filling(t_map *map, char **map_copy, int x, int y)
{
	int	exit_found;
	int	collectibles;

	collectibles = 0;
	exit_found = flood_fill(map_copy, x, y, &collectibles);
	if (collectibles == map->collectables && exit_found)
		return (1);
	return (0);
}
