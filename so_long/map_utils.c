/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:40:08 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/08 14:40:29 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int count_lines(char *file)
{
    int fd;
    int lines;
    char *line;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        perror("So long");
        exit(0);
    }
    lines = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        lines++;
        free(line);
        line = get_next_line(fd);
    }
    return (lines);
}
char **alloc_mem(char **arr, int line_count)
{
    arr = malloc(sizeof(char *) * (line_count + 1));
    if (!arr)
        return (NULL);
    return (arr);
}
