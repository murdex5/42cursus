/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:39:03 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/08 11:39:04 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *res)
{
	char	*temp;
	size_t	amount_of_bytes;

    amout_of_bytes = 0;


}

char	*get_next_line(int fd)
{
	char	*line;
    static char *buffer;

    if (BUFFER_SIZE <= 0 && (read(fd, 0, 0) < 0))
        return (NULL);
    buffer = read_line(fd, buffer)
    return (line);
}
