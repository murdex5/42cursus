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

// static int	read_ber(int fd,  unsigned char *buffer)
// {
// 	int	bytes_read;

// 	bytes_read = read(fd, buffer, sizeof(buffer));
// 	if (bytes_read == -1)
// 	{
// 		perror("So long");
// 		close(fd);
// 		exit(1);
// 	}
// 	return (bytes_read);
// }

int	parsing_map(char *file)
{
	int				fd;
	unsigned char	buffer[256];
	int				bytes_read;
	int				i;
	int				j;
	int				length;
	int				value;

	j = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Couldn't open the map error: %d\n", fd);
		perror("So long");
		return (1);
	}
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read == -1)
	{
		perror("So long");
		close(fd);
		exit(1);
	}
    close(fd);
	while (i < bytes_read)
	{
		if (buffer[i] == 0x02)
		{
			length = buffer[i + 1];
			value = 0;
            j = 0;
			while (j < length)
			{
				value = (value << 8) | buffer[i + 2 + j];;
				j++;
			}
            i += 1 + length;
            ft_printf("Found value: %d\n", value);
		}
		i++;
	}
	return (0);
}
