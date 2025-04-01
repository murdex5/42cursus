/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                     +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:54:01 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/01 14:54:01 by kadferna         ###   ########.ch       */
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

typedef enum e_bool
{
	TRUE,
	FALSE
}			t_bool;

typedef struct s_pip
{
	int		in_fd[2];
	int		out_fd[2];
	t_bool	here_doc;
	t_bool	is_invalid_infile;
	char	**cmd_path;
	char	***cmd_args;
	int		cmd_count;
}			t_pip;

t_pip		*init_pip(void);
int			std_errors(char *msg);
int			ft_strcmp(const char *s1, const char *s2);
int			err_p(char *msg);
int			check_ac(int ac);
void		close_fd(int fd1, int fd2);
void		reknew_fd(int (*p)[2]);
t_bool		check_here_doc(char **argv);
int			check_args(int argc, char **argv, t_pip *pip);
void		clean_up(t_pip *pip);
#endif