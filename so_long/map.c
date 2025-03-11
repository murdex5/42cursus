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

static t_map	*map_init(void)
{
	t_map	*map;

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

static t_map	*map_pop(t_map *map, char *file)
{
	if (!read_map_file(map, file))
	{
		free_map(map);
		return (error_message("Couldn't read to the file"), NULL);
	}
	if (!store_player_position(map))
	{
		free_map(map);
		return (error_message("Filed to store player position"), NULL);
	}
	if (!check_map(map))
	{
		free_map(map);
		return (error_message("The map is invalid"), NULL);
	}
	return (map);
}

t_map	*parsing_map(char *file)
{
	t_map	*map;
	int		line_count;

	if (!check_file_type(file, ".ber"))
		return (error_message("Wrong file type."), NULL);
	line_count = count_lines(file);
	map = map_init();
	if (!map)
		return (error_message("Map initialization failed"), NULL);
	if (!alloc_mem(map, line_count))
		return (error_message("Memory allocation Failed"), NULL);
	map->height = line_count;
	map = map_pop(map, file);
	return (map);
}
