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

int	check_one(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}
