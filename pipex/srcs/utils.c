/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:39:42 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/31 13:39:43 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_fd(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
void	reknew_fd(int (*p)[2])
{
	close_fd((*p)[0], (*p)[1]);
	pipe((*p));
}