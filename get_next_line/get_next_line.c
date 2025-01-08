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

char	*get_next_line(int fd)
{
    char buf[BUFSIZ];
    ssize_t n;
    char *line;
    int i;
    int j;
    size_t line_size;

    j = 0;
    i = 0;
    line_size = BUFSIZ;
    if (fd == -1)
        return (NULL);
    line = malloc(line_size);
    if (!line)
        return (NULL);
    while ((n = read(fd, buf, BUFSIZ)) > 0)
    {
        while (i < n)
        {
            if (buf[i] == '\n')
            {
                line[j] = '\0';
                return (line);
            }

            if (j >= line_size - 1)
            {
                line_size *= 2;
                line = realloc(line, line_size);
                if (!line)
                    return (NULL);
            }
            line[j++] = buf[i];
            i++;
        }
    }
    if (n == 0 && j > 0)
    {
        line[j] = '\0';
        return (line);
    }
    if (n < 0)
    {
        free(line);
        return NULL;
    }
    return (line);
}

int	main(void)
{
	int fd = open("text.txt", O_RDWR | O_CREAT, 0777);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
    char *str = get_next_line(fd);
    printf("%s\n", str);
    free(str);    
}