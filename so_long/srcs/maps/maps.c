/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:34:40 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/09 13:34:42 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_surrounded(t_map *map)
{
	int	i;

	i = 0;
	while (map->content[i])
	{
		if (map->content[i][0] && map->content[i][0] != '1')
			return (0);
		if (map->content[i][0] == '1')
		{
			if (map->content[i][map->width - 1] && map->content[i][map->width
				- 1] != '1')
				return (0);
		}
		i++;
	}
	if (!check_one(map->content[0], '1'))
		return (0);
	else if (!check_one(map->content[map->height - 1], '1'))
		return (0);
	return (1);
}

t_map	*parse_map(char *path)
{
	t_map	*map;

	if (!check_file_type(path))
		return (NULL);
	map = init_map();
	if (!map)
		return (free_error("Couldn't initialize the map", map), NULL);
	map = map_pop(map, path);
	if (!map)
		return (NULL);
	if (!check_map(map))
		return (free_error(NULL, map), NULL);
	return (map);
}
