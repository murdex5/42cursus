/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:23:51 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/22 12:27:40 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include "get_next_line_bonus.h"

int main(void)
{
    int fd1, fd2, fd3, fd4;
    char *line1, *line2, *line3, *line4;

    fd1 = open("text1.txt", O_RDONLY);
    if (fd1 < 0)
    {
        perror("Couldn't open text1.txt");
        return (1);
    }

    fd2 = open("text2.txt", O_RDONLY);
    if (fd2 < 0)
    {
        perror("Couldn't open text2.txt");
        close(fd1);
        return (1);
    }

    fd3 = open("empty.txt", O_RDONLY);
    if (fd3 < 0)
    {
        perror("Couldn't open empty.txt");
        close(fd1);
        close(fd2);
        return (1);
    }

    fd4 = open("large.txt", O_RDONLY);
    if (fd4 < 0)
    {
        perror("Couldn't open large.txt");
        close(fd1);
        close(fd2);
        close(fd3);
        return (1);
    }

    line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);
    line3 = get_next_line(fd3);
    line4 = get_next_line(fd4);

    while (line1 != NULL || line2 != NULL || line3 != NULL || line4 != NULL)
    {
        if (line1 != NULL)
        {
            printf("File 1: %s", line1);
            free(line1);
            line1 = get_next_line(fd1);
        }
        if (line2 != NULL)
        {
            printf("File 2: %s", line2);
            free(line2);
            line2 = get_next_line(fd2);
        }
        if (line3 != NULL)
        {
            printf("File 3 (empty): %s", line3);
            free(line3);
            line3 = get_next_line(fd3);
        }
        if (line4 != NULL)
        {
            printf("File 4 (large): %s", line4);
            free(line4);
            line4 = get_next_line(fd4);
        }
    }

    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
    return (0);
}

