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

static void	free_map(char **map_arr)
{
	int	i;

	i = 0;
	while (map_arr[i])
	{
		free(map_arr[i]);
		i++;
	}
	free(map_arr);
}

static int	flood_fill(char **map_copy, int x, int y, int *collectable_count)
{
	int	exit_found;

	exit_found = 0;
	if (map_copy[y][x] == '1')
		return (0);
	if (map_copy[y][x] == 'E')
		exit_found = 1;
	if (map_copy[y][x] == 'C')
		(*collectable_count)++;
	map_copy[y][x] = 1;
	exit_found |= flood_fill(map_copy, x + 1, y, collectable_count);
	exit_found |= flood_fill(map_copy, x - 1, y, collectable_count);
	exit_found |= flood_fill(map_copy, x, y + 1, collectable_count);
	exit_found |= flood_fill(map_copy, x, y - 1, collectable_count);
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

	map_copy = copy_map(map->content);
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
				return (exit_count);
			}
			x++;
		}
		y++;
	}
	free_map(map_copy);
	return (0);
}


int	check_map(t_map *map)
{
    if (!if_map_rectangled(map))
        return (error_message("Map is not recatngular."));
    if (!if_map_sorrounded(map))
        return (error_message("Map is not surrounded by walls."));
    if (!check_map_contents(map))
        return (error_message("Map contains invalid characters"));
    if (map->player_count != 1)
        return (error_message("Invalid Player count."));
    if (map->exit_count != 1)
        return (error_message("Must have One exit."));
    if (map->collectables > 1)
        return (error_message("The map must have atleast One collectible."));
    if (check_path(map))
        return (error_message("Map does not have a valid path."));
	return (1);
}