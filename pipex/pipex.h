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
typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	t_bool	here_doc;
	t_bool	is_invalid_infile;
	char	**cmd_paths;
	char	***cmd_args;
	int		cmd_count;
}			t_pipex;

int			free_ptr_arr(char ***str_arr, int i);
int			free_arr(char **str_arr, int i);
void		ft_cleanup(t_pipex *pipex);
int			err_p(char *err_type);
t_bool		ft_check_here_doc(char **argv);
int			ft_check_args(int argc, char **argv, t_pipex *pipex);
char		*ft_get_exe(char *cmd, char **paths);
char		**ft_get_path(char **env);
t_pipex		*ft_init_pipex(void);
char		***ft_parse_args(int argc, char **argv, t_pipex *pipex);
char		**ft_parse_cmds(int argc, char **argv, t_pipex *pipex,
				char *envp[]);
#endif