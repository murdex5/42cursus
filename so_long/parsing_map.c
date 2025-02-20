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

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Couldn't open the file. Error: %d\n", fd);
		perror("So long");
		return (fd);
	}
	return (fd);
}

int	read_file(char *file, unsigned char *buffer)
{
	int	read_bytes;
	int	fd;

	fd = open_file(file);
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
t_map_dims	get_dims(unsigned char *buffer, int bytes_read, int length,
		int value, int i, int j)
{
	int			dimension_count;
	t_map_dims	dims;

	dimension_count = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == 0x02)
		{
			length = buffer[i + 1];
			value = 0;
			j = 0;
			while (j < length)
			{
				value = (value << 8) | buffer[i + 2 + j];
				j++;
			}
			if (dimension_count == 0)
				dims.width = value;
			else if (dimension_count == 1)
				dims.height = value;
			dimension_count++;
			i += length + 2;
		}
		else
			i++;
	}
	return (dims);
}

t_map_dims	parsing_map(char *map)
{
	t_map_dims		dims;
	unsigned char	buffer[256];
	int				bytes_read;
	int				length;
	int				value;
	int				i;
	int				j;

	i = 0;
	j = 0;
	length = 0;
	value = 0;
	dims.height = 0;
	dims.width = 0;
	bytes_read = read_file(map, buffer);
	if (bytes_read == -1)
		return (dims);
	dims = get_dims(buffer, bytes_read, length, value, i, j);
	return (dims);
}
