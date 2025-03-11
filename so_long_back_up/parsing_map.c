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
	map->content[i] = NULL;
	close(fd);
	return (1);
}

static int	store_player_position(t_map *map)
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

void	clean_up(t_map *map)
{
	int	i;

	i = 0;
	if (map->content)
	{
		while (i < map->height && map->content[i])
		{
			free(map->content[i]);
			i++;
		}
		free(map->content);
	}
	free(map);
}

static t_map	*populating_map(t_map *map, char *file)
{
	if (!read_map_file(map, file))
	{
		clean_up(map);
		error_message("Couldn't read to the file");
		return (NULL);
	}
	if (!store_player_position(map))
	{
		clean_up(map);
		error_message("Failed to store player position");
		return (NULL);
	}
	if (!check_map(map))
	{
		clean_up(map);
		error_message("The map is invalid");
		return (NULL);
	}
	return (map);
}

t_map	*parsing_map(char *file)
{
	t_map	*map;
	int		line_count;

	if (!check_file_type(file, ".ber"))
		return (error_message("Wrong File Type."), NULL);
	line_count = count_lines(file);
	if (line_count <= 0)
		return (error_message("Failed to read the file type"), NULL);
	map = create_map();
	if (!map)
		return (error_message("Memory allocation failed"), NULL);	
	map->content = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!map->content)
	{
		free(map);
		return (error_message("Memory allocation failed"), NULL);
	}
	map->content[line_count] = NULL;
	map->height = line_count;
	map = populating_map(map, file);
	return (map);
}
