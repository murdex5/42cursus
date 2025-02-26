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

static t_map *create_map(void)
{
    t_map *map;

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->content = NULL;
    map->player_count = 0;
    map->exit_count = 0;
    map->collectables = 0;
    map->height = 0;
    map->width =0;
    map->player_x = -1;
    map->player_y = -1;
    return (map);
}

static int count_lines(char *file)
{
    char *line;
    int line_count;
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        perror("So long");
        return (0);
    }
    line = get_next_line(fd);
}
