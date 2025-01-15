/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:37:33 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/15 14:37:35 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *buf, char *buffer)
{
	int		read_count;
	char	*temp;

	read_count = 1;
	while (read_count != 0)
	{
		read_count = read(fd, buf, BUFFER_SIZE);
		if (read_count == -1)
			return (0);
		buf[read_count] = '\0';
		if (read_count == 0)
			break ;
		if (!buffer)
			buffer = ft_strdup("");
		temp = buffer;
		buffer = ft_strjoin(buffer, buf);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
		temp = NULL;
	}
	return (buffer);
}

char	*clean_up(char *line)
{
	int		count;
	char	*buf;

	count = 0;
	while (line[count] != '\n' && line[count])
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	buf = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*buf == '\0')
	{
		free(buf);
		buf = NULL;
	}
	line[count + 1] = '\0';
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, &buffer, 0)) < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = get_line(fd, buf, buffer);
	return (line);
}
