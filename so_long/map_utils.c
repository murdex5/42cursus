/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:40:08 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/08 14:40:29 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_str(char **content, int i)
{
	while (i > 0)
		free(content[--i]);
	free(content);
	return (0);
}

int	check_file_type(char *file, char *type)
{
	char	*dot;
	int		i;
	int		j;

	dot = malloc(sizeof(char) * 5);
	if (!dot)
		return (0);
	i = (int)ft_strlen(file) - 5;
	j = -1;
	while (file[i] != '\0')
	{
		dot[++j] = file[++i];
	}
	dot[j] = '\0';
	if (ft_strncmp(dot, type, ft_strlen(type)) == 0)
	{
		free(dot);
		return (1);
	}
	else
	{
		free(dot);
		return (0);
	}
}

int	count_lines(char *file)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("So long");
		exit(0);
	}
	lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	return (lines);
}
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

char	**copy_map(t_map *map)
{
	char	**map_copy;
	int		i;

	map_copy = (char **)malloc(sizeof(char *) * (map->height));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		map_copy[i] = ft_strdup(map->content[i]);
		if (!map_copy[i])
		{
			while (i > 0)
				free(map_copy[--i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	return (map_copy);
}
int	flood_fill(char **map, int x, int y, int *collectibles)
{
	int	exit_found;

	if (x < 0 || y < 0 || !map[y] || map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	exit_found = 0;
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
