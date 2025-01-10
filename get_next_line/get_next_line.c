/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:58:12 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/10 14:58:15 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;
    return (line);
}

char *read_line(int fd, char *res)
{
    char *buffer;
    int read_err;

    if (!res)
        res = ft_calloc(1, 1);
    buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
    read_err = 1;
    while (read_err > 0)
    {
        read_err = read(fd, buffer, BUFFER_SIZE);
        if (read_err == -1)
        {
            free(buffer);
            return (NULL);
        }
        res = ft_strjoin(buffer, res);
        free(buffer);
    }
    free(buffer);
    return (res);
}

char *get_line ?