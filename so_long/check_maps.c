#include "so_long.h"


int	check_file_type(char *file, char *type)
{
	char *dot;

	dot = ft_strchr(file, '.');
	if (!dot)
		return (0);
	if (ft_strlen(dot) != ft_strlen(type))
		return (0);
	if (ft_strncmp(dot, type, ft_strlen(type)) == 0)
		return (1);
	else
		return (0);
}

int	if_map_rectangled(t_map *map)
{
	int first_line_lentgh;
	int i;

	if (!map || !map->content || !map->content[0])
		return (0);
	first_line_lentgh = ft_strlen(map->content[0]);
	i = 0;
	while (i < map->height)
	{
		if ((int)ft_strlen(map->content[i]) != first_line_lentgh)
			return (0);
		i++;
	}
	map->width = first_line_lentgh;
	return (1);
}

int	if_map_sorrounded(t_map *map)
{
	int i;
	int j;

	if (!map || !map->content ||  map->width <= 0 || map->height <= 0)
		return (0);
	
	i = 0;
	while (i < map->width)
	{
		if (map->content[0][i] != '1')
			return (0);
		if (map->content[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (j < map->height)
	{
		if (map->content[j][0] != '1')
			return (0);
		if (map->content[j][map->width - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_map_contents(t_map *map)
{
	int i;
	int j;

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
			else
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	error_message(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}