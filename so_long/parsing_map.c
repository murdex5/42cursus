/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:06:27 by kadferna          #+#    #+#             */
/*   Updated: 2025/02/26 10:06:30 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	*create_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->content = NULL;
	map->player_count = 0;
	map->exit_count = 0;
	map->collectables = 0;
	map->height = 0;
	map->width = 0;
	map->player_x = -1;
	map->player_y = -1;
	return (map);
}

static int	count_lines(char *file)
{
	char	*line;
	int		line_count;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("So long");
		return (-1);
	}
	line_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

static int	free_str(char **content, int i)
{
	while (i > 0)
		free(content[--i]);
	free(content);
	return (0);
}
static int	read_map_file(t_map *map, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("So long");
		return (0);
	}
	i = 0;
	line = get_next_line(fd);
	while (line = get_next_line(fd) != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map->content[i] = ft_strdup(line);
		free(line);
		if (!map->content[i])
			return (free_str(map->content[i], i));
		i++;
	}
	close(fd);
	return (1);
}

t_map	*parsing_map(char *file)
{
	t_map *map;

    if (!check_file_type(file, ".ber"))
		return (error_message("Wrong File Type."));
}
