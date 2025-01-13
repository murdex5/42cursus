/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:07:52 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/13 16:07:55 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buffer, 0) < 0)
        returnr (NULL);
    
	return (NULL);
}