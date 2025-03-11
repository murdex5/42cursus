/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:01:36 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/08 15:01:48 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangled(t_map *map)
{
	int	first_line_length;
	int	i;

	if (!map || !map->content || !map->content[0])
		return (0);
	first_line_length = ft_strlen(map->content[0]);
	i = 0;
	while (i < map->height)
	{
		if ((int)ft_strlen(map->content[i]) != (int)first_line_length)
			return (0);
		i++;
	}
	map->width = first_line_length;
	return (1);
}

int	if_map_surrounded(t_map *map)
{
	int	x;
	int	y;

	if (!map || !map->content || !map->content[0] || map->width <= 0
		|| map->height <= 0)
		return (0);
	x = 0;
	while (x < map->width)
	{
		if (map->content[0][x] != '1' || map->content[map->height - 1][x])
			return (0);
		x++;
	}
	y = 1;
	while (y < map->height - 1)
	{
		if (map->content[y][0] != '1' || map->content[y][map->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_map_contents(t_map *map)
{
	int	i;
	int	j;

	map->collectables = 0;
	map->exit_count = 0;
	map->player_count = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->content[i][j] == 'P')
				map->player_count++;
			else if (map->content[i][j] == 'E')
				map->exit_count++;
			else if (map->content[i][j] == 'C')
				map->collectables++;
			else if (map->content[i][j] != '0' && map->content[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
static int	flood_filling(t_map *map, char **map_copy, int x, int y)
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
	int		result;

	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	result = flood_filling(map, map_copy, map->player_x, map->player_y);
	free_map_content(map_copy, map->height);
	return (result);
}

int	check_map(t_map *map)
{
	if (!is_rectangled(map))
		return (error_message("Map is not rectangular."), 0);
	if (if_map_surrounded(map))
		return (error_message("Map is not surrounded my walls."), 0);
	if (!check_map_contents(map))
		return (error_message("Map contains Invalid characters"), 0);
	if (map->player_count != 1)
		return (error_message("Invalid Player Count"), 0);
	if (map->exit_count != 1)
		return (error_message("Must have One exit."), 0);
	if (map->collectables < 1)
		return (error_message("The map must have atleast One collectible."), 0);
	if (!check_path(map))
		return (error_message("Map does not have a valid path."), 0);
	return (1);
}
