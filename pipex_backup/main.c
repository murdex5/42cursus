/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:46:39 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/26 09:46:41 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_arr_lenth(char ***str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != NULL)
	{
		i++;
	}
	return (i);
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipex	*pipex;
	int		pipe_fd[2];
	int		i;

	if (argc < 5)
	{
		ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		ft_printf("   or: ./pipex here_doc DELIMITER cmd1 cmd2 .... cmdn file\n");
		;
		return (1);
	}
	pipex = ft_init_pipex();
	if (!pipex)
		return (1);
	pipex->here_doc = ft_check_here_doc(argv);
	if (!ft_check_args(argc, argv, pipex))
		return (1);
	pipex->cmd_args = ft_parse_args(argc, argv, pipex);
	if (!pipex->cmd_args)
	{
		free(pipex);
		return (1);
	}
	pipex->cmd_paths = ft_parse_cmds(argc, argv, envp);
	if (!pipex->cmd_paths)
	{
		free_ptr_arr(pipex->cmd_args, get_arr_lenth(pipex->cmd_args));
		free(pipex);
		return (1);
	}
	if (pipe(pipe_fd) == -1)
	{
		err_p("pipe");
		ft_cleanup(pipex);
		return (1);
	}
	i = 0;
	while (pipex->cmd_paths[i] != NULL)
	{
		if (ft_exec(pipex, pipe_fd, i) < 0)
		{
			ft_cleanup(pipex);
			return (1);
		}
		i++;
	}
	ft_wait(i);
	ft_close_fd(pipe_fd[0], pipe_fd[1]);
	ft_write_fd(pipex->cmd_paths[i-1], pipex->in_fd, pipex->here_doc);
	ft_cleanup(pipex);
	ft_printf("Program finished successfully\n");
	return (0);
}
