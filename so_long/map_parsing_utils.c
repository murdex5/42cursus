/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:22:25 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/11 15:22:40 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	store_player_position(t_map *map)
{
	int	i;
	int	j;

	if (!map->content || !map->content[0])
		return (0);
	i = 0;
	map->width = (int)ft_strlen(map->content[0]);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->content[i][j] == 'P')
			{
				map->player_x = i;
				map->player_y = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	read_map_file(t_map *map, char *file)
{
	int fd;
	int i;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("So long");
		return (0);
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map->content[i] = ft_strdup(line);
		free(line);
		if (!map->content[i])
			return (free_str(map->content, i));
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}