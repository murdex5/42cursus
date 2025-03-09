/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:06:04 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/08 15:09:56 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map *map_init()
{
	t_map *map;

	map = NULL;
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->content = NULL;
	map->collectables = 0;
	map->exit_count = 0;
	map->height = 0;
	map->player_count = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->width = 0;
	return (map);
}


t_map *parsing_map(char *file)
{
	t_map *map;
	int line_count;

	line_count = count_lines(file);
	map = map_init();
	if (!map)
		return (NULL);
	if (alloc_mem(map->content, line_count) == NULL)
		return (NULL);
}
