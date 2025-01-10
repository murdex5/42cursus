/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:11:17 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/10 11:11:18 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buff)
{
	char	*temp;

	temp = ft_strjoin(buffer, buff);
	free(buffer);
	return (temp);
}

char	*get_line(int fd, char *res)
{
	char	*buffer;
	int		read_err;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_err = 1;
	while (read_err > 0)
	{
		read_err = read(fd, buffer, BUFFER_SIZE);
		if (read_err == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_err] = 0;
		res = ft_free(res, buffer);
	}
	free(buffer);
	return (res);
}
char *read_line(char *)

char	*get_next_line(int fd)
{
	static char *buffer;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);

	return (line);
}