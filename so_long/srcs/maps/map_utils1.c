/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:18:56 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/10 12:19:01 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**copy_map(t_map *map)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_calloc(sizeof(char *), map->height + 1);
	if (!str)
		return (NULL);
	while (i < map->height)
	{
		str[i] = ft_strdup(map->content[i]);
		if (!str[i])
		{
			free_ifnot_null(str);
			return (NULL);
		}
		i++;
	}
	str[map->height] = NULL;
	return (str);
}

int	flood_filling(t_map *map, char **map_copy, int x, int y)
{
	int	exit_found;
	int	collectibles;

	collectibles = 0;
	exit_found = flood_fill(map_copy, x, y, &collectibles);
	if (collectibles == map->collectibles && exit_found)
		return (1);
	return (0);
}
