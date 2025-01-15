/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:50:26 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/15 12:04:04 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_list(t_list **list, int fd)
{
	char	*buffer;
	int		read_chars;

	while (!find_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		read_chars = read(fd, buffer, BUFFER_SIZE);
		if (read_chars <= 0)
		{
			free(buffer);
			break ;
		}
		buffer[read_chars] = '\0';
		append(list, buffer);
	}
}

char	*get_line(t_list *list)
{
	char	*line;
	int		str_len;

	str_len = list_str_len(list);
	line = malloc(str_len + 1);
	if (!line)
		return (NULL);
	copy_str(list, line);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &list, 0) < 0)
		return (NULL);
	return (line);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	line = get_line(list);
	if (!line)
		return (NULL);
	polish_list(&list);
	return (line);
}
