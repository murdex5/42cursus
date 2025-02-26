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

void	free_map(char **map_arr)
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


int	check_map(int argc, char **argv, t_map *map)
{
	char *file;

	if (argc != 2)
		return (1);
	file = argv[1];
	if (!check_file_type(file, ".ber"))
        return (error_message("Wrong File Type"));
    if (!if_map_rectangled(map))
        return (error_message("Map is not recatngular"));
    if (!if_map_sorrounded(map))
        return (error_message("Map is not surrounded by walls"));
	return (1);
}