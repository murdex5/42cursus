/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:11:58 by kadferna          #+#    #+#             */
/*   Updated: 2025/02/20 12:12:00 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int open_file(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Couldn't open the file. Error: %d\n", fd);
        perror("So long");
        return (fd);
    }
    return (fd);
}

int read_file(char *file, unsigned char *buffer)
{
    int read_bytes;
    int fd;

    fd =  open_file(file);
    if (fd == -1)
        return (fd);
    read_bytes = read(fd, buffer, 256);
    if (read_bytes == -1)
    {
        ft_printf("Couldn't read the file. Error: %d\n", read_bytes);
        perror("So long");
        close(fd);
        return (read_bytes);
    }
    close(fd);
    return (read_bytes);
}

t_map_dims     parsing_map(char *map)
{
    t_map_dims dims;
    unsigned char buffer[256];
    int bytes_read;

    dims.height = 0;
    dims.width = 0;
    bytes_read == read_file(map, buffer);
    if (bytes_read == -1)
        return (dims);
}
