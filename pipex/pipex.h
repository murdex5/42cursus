/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                     +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:33:10 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/01 15:42:27 by kadferna         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <wait.h>

typedef enum e_bool
{
	TRUE,
	FALSE
}			t_bool;

typedef struct s_pip
{
	int		fd[2];
	t_bool	here_doc;
	t_bool	is_invalid_infile;
	char	**cmd_path;
	char	***cmd_args;
	int		cmd_count;
}			t_pip;

t_pip		*init_pip(void);
char		**get_path(char *env[]);
void		free_arr_arr(char ***str, int i);
int			free_two_vals(char **arr1, char **arr2, int i, char **path);
void		free_cmd_path(char **str);
void		free_args(char ***str);
void		free_arr(char **str, int i);
int			std_errors(char *msg);
int			ft_strcmp(const char *s1, const char *s2);
int			err_p(char *msg);
int			check_ac(int ac);
void		close_fd(int fd1, int fd2);
void		reknew_fd(int (*p)[2]);
t_bool		check_here_doc(char **argv);
char		***parse_args(int argc, char **argv);
char		**parse_paths(int argc, char **argv, char *envp[], int offset);
int			check_args(int argc, char **argv, t_pip *pip);
char		*get_exe(char *cmd, char **paths);
t_pip		*populate_pip(int argc, char **argv, char *envp[]);
void		ft_clean_up(t_pip *pip);
void		ft_exec(t_pip *pip, char *path, char *envp[]);
#endif