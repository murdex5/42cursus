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

t_map	*init_map(void)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (NULL);
	map->collectibles = 0;
	map->content = NULL;
	map->exits = 0;
	map->height = 0;
	map->widht = 0;
	return (map);
}

t_map	*check_map(char *path)
{
	t_map	*map;

	if (!check_file_type(path))
		return (NULL);
	map = init_map();
	if (!map)
		return (NULL);
	map->content = ft_calloc(sizeof(char *), (size_t)count_lines(path));
	if (!map->content)
		return (NULL);
	if (!read_map_files(map, path))
		return (NULL);
	return (map);
}
