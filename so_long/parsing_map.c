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

int bytes_read(char *map, unsigned char *buffer)
{
	int fd;
	int bytes_read;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Couldn't open the file, Error: %d\n", fd);
		perror("So long");
		return(fd);
	}
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read == -1)
	{
		close(fd);
		perror("So long");
		return(bytes_read);
	}
	close(fd);
	return (bytes_read);
}

t_map_dims parsing_map(char *file)
{
    int fd;
    unsigned char buffer[256];
    int bytes_read;
    int i;
    int j;
    t_map_dims dims = {0, 0};
    int value;
    int dimension_count = 0;

    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Error: Could not open map file\n");
        return dims;
    }
    
    bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1)
    {
        close(fd);
        ft_printf("Error: Could not read map file\n");
        return dims;
    }
    close(fd);

    i = 0;
    while (i < bytes_read && dimension_count < 2)
    {
        if (buffer[i] == 0x02)  // Start of new value marker
        {
            int length = buffer[i + 1];  // Get length of value
            value = 0;
            j = 0;
            while (j < length)
            {
                value = (value << 8) | buffer[i + 2 + j];
                j++;
            }
            
            // First value is width, second is height
            if (dimension_count == 0)
                dims.width = value;
            else if (dimension_count == 1)
                dims.height = value;
            
            dimension_count++;
            i += length + 2;  // Skip marker, length byte, and value bytes
        }
        else
            i++;
    }

    return dims;
}