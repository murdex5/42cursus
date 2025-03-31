/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:39:00 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/26 09:39:13 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "sys/wait.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	close_fd(int fd1, int fd2);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_unlink(char *file);
int		check_ac(int ac);
int		err_p(char *msg);
void	reknew_pipe(int (*p)[2]);
void	read_here_doc(char *limiter, int fd_out);
int		check_here_doc(char **argv, int (*p)[2]);

#endif