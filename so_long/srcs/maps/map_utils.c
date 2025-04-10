/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:50:43 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/09 14:50:46 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	count_lines(char *file)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("So long");
		return (0);
	}
	lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	get_hw(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->content[i])
		i++;
	j = 0;
	while (map->content[i - 1][j])
		j++;
	map->height = i;
	map->width = j;
}

int	read_map_files(t_map *map, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("So long");
		exit(1);
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
			return (free_n_returnt(map->content, NULL, NULL), 0);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	check_rectangular(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	get_hw(map);
	while (map->content[i])
	{
		j = 0;
		while (map->content[i][j])
			j++;
		if (j != map->width)
			return (0);
		i++;
	}
	if (i != map->height)
		return (0);
	return (1);
}
