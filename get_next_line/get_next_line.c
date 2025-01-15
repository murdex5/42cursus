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


char	*get_line(t_list *list)
{
	char	*line;
	int		str_len;

	str_len = list_str_len(list);
	if (str_len == 0)
		return (NULL);
	line = malloc(str_len + 1);
	if (!line)
		return (NULL);
	copy_str(list, line);
	return (line);
}

void    create_list(t_list **list, int fd)
{
    char    *buffer;
    int     read_chars;

	if (!list)
		return ;
    while (!find_newline(*list))
    {
        buffer = malloc(BUFFER_SIZE + 1);
        if (!buffer)
        {
            return;
        }
        read_chars = read(fd, buffer, BUFFER_SIZE);
        if (read_chars <= 0)
        {
            free(buffer);
            return;
        }
        buffer[read_chars] = '\0';
        append(list, buffer);
        if (read_chars < BUFFER_SIZE)
            break;
    }
}


char    *get_next_line(int fd)
{
    static t_list    *list;
    char            *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
    {
        if (list)
        {
            polish_list(&list);
            list = NULL;
        }
        return (NULL);
    }
    create_list(&list, fd);
    if (!list)
    {
        return (NULL);
    }
    line = get_line(list);
    if (!line)
    {
        polish_list(&list);
        list = NULL;
        return (NULL);
    }
    polish_list(&list);
    return (line);
}