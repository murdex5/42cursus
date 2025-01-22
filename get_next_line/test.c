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

int main(void)
{
	int fd;
	char *line;

	int count;

	fd = open("text2.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Couldn't open the file");
		return (1);
	}
	line = get_next_line(fd);
	
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return(0);
}

