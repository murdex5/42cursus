/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:11:33 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/31 10:11:37 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_fd(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	reknew_pipe(int (*p)[2])
{
	close_fd((*p)[0], (*p)[1]);
	pipe((*p));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_unlink(char *file)
{
	if (access(file, X_OK) == 0)
		unlink(file);
	return (0);
}