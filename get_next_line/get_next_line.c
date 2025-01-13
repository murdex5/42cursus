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

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;
	int		i;

	while (!find_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		char_read = read(fd, &list, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
        append(*list, buf);
	}
}

char    *get_line(t_list *list)
{
    char    *line;
    int str_len;

    str_len = get_len_lists(list);
    line = malloc(str_len + 1);
    if (!line)
        return (NULL);
    copy_str(list, line);
}

void clean_list(t_list **list)
{
    t_list *clean_list;
    t_list *last_node;
    int i;
    int k;
    char *buf;

    buf = malloc(BUFFER_SIZE + 1);
    clean_list = malloc(sizeof(t_list));
    if (!buf || !clean_list)
        return ;
    last_node = find_last_node(list);

    i = 0;
    k = 0;
    while (last_node->buff[i] != '\0' && last_node->buff[i] ==  '\0')
        ++i;
    while (last_node->buff[i] != '\0' && last_node->buff[++i])
        buf[k++] = last_node->buff[++i];
    buf[k] = '\0';
    clean_list->buff = buf;
    clean_list->next = NULL;

}

char	*get_next_line(int fd)
{
	static t_list *list;
	char *next_line;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &list, 0) < 0)
		return (NULL);
    create_list(&list, fd);
    if (list == NULL)
        return (NULL);
    clean_list(&list);
	return (next_line);
}


int main(void)
{
    int fd;
    char *line;
    int lines;

    lines = 1;
    fd = open("text.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
        printf("%d->%s\n", lines++, line);
    return (0);
}