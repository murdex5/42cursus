/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:34:40 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/09 13:34:42 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (NULL);
	map->collectibles = 0;
	map->content = NULL;
	map->exits = 0;
	map->height = 0;
	map->width = 0;
	return (map);
}

int	check_collectibles(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->content[i])
	{
		j = 0;
		while (map->content[i][j])
		{
			if (map->content[i][j] == 'C')
				map->collectibles++;
			j++;
		}
		i++;
	}
	if (map->collectibles == 0)
		return (0);
	return (1);
}

int	check_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->content[i])
	{
		j = 0;
		while (map->content[i][j])
		{
			if (map->content[i][j] == 'P')
			{
				map->player_y = i;
				map->player_x = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_exits(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->content[i])
	{
		j = 0;
		while (map->content[i][j])
		{
			if (map->content[i][j] == 'E')
				map->exits++;
			j++;
		}
		i++;
	}
	if (map->exits == 0)
		return (0);
	return (1);
}

t_map	*check_map(char *path)
{
	t_map	*map;

	if (!check_file_type(path))
		return (NULL);
	map = init_map();
	if (!map)
		return (free_error("Couldn't initialize the map", map), NULL);
	map->content = ft_calloc(sizeof(char *), (count_lines(path) + 1));
	if (!map->content)
		return (free_error("Memory allocation for content is failed", map),
			NULL);
	if (!read_map_files(map, path))
		return (free_error("Failed to read the map file", map), NULL);
	map->content[count_lines(path)] = NULL;
	if (!check_rectangular(map))
		return (free_error("The map should be rectangular", map), NULL);
	if (!check_exits(map))
		return (free_error("Couldn't find any exits in the map", map), NULL);
	if (!check_collectibles(map))
		return (free_error("There should be atleast One collectible", map),
			NULL);
	if (!check_player(map))
		return (free_error("Couldn't find the player in the map", map), NULL);
	return (map);
}
