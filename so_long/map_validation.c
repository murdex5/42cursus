/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:06:39 by kadferna          #+#    #+#             */
/*   Updated: 2025/02/26 10:06:41 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(t_map *map)
{
	char	**map_copy;
	int		i;

	map_copy = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		map_copy[i] = ft_strdup(map->content[i]);
		if (!map_copy)
		{
			while (i > 0)
				free(map_copy[--i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}


static int	flood_fill(char **map, int x, int y, int *collectibles)
{
	int	exit_found;

	exit_found = 0;
	if (x < 0 || y < 0 || !map[y] || map[y][x] || map[y][x] == '1'
		|| map[y][x] == 'V')
		return (0);
	if (map[y][x] == 'E')
		exit_found = 1;
	if (map[y][x] == 'C')
		(*collectibles)++;
	map[y][x] = 'V';
	exit_found |= flood_fill(map, x + 1, y, collectibles);
	exit_found |= flood_fill(map, x - 1, y, collectibles);
	exit_found |= flood_fill(map, x, y + 1, collectibles);
	exit_found |= flood_fill(map, x, y - 1, collectibles);
	return (exit_found);
}

static int	flodd_filling(t_map *map, char **map_copy, int x, int y)
{
	int	exit_found;
	int	collectibles;

	collectibles = 0;
	exit_found = flood_fill(map_copy, x, y, &collectibles);
	if (collectibles == map->collectables && exit_found)
		return (1);
	return (0);
}

int	check_path(t_map *map)
{
	char	**map_copy;
	int		x;
	int		y;
	int		exit_count;

	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->content[y][x] == 'P')
			{
				exit_count = flodd_filling(map, map_copy, x, y);
				free_map_content(map_copy, map->height);
				return (exit_count);
			}
			x++;
		}
		y++;
	}
	free_map_content(map_copy, map->height);
	return (0);
}

int	check_map(t_map *map)
{
	if (!if_map_rectangled(map))
		return (error_message("Map is not recatngular."), 0);
	if (!if_map_sorrounded(map))
		return (error_message("Map is not surrounded by walls."), 0);
	if (!check_map_contents(map))
		return (error_message("Map contains invalid characters"), 0);
	if (map->player_count != 1)
		return (error_message("Invalid Player count."), 0);
	if (map->exit_count != 1)
		return (error_message("Must have One exit."), 0);
	if (map->collectables > 1)
		return (error_message("The map must have atleast One collectible."), 0);
	if (check_path(map))
		return (error_message("Map does not have a valid path."), 0);
	return (1);
}