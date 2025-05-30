/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:48:39 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/28 11:48:52 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	ft_exec(t_pipex *pipex, char **env)
// {
// 	if (!pipex || !pipex->cmd_paths || !pipex->cmd_args)
// 	{
// 		ft_pipex_err("Invalid arguments to ft_exec");
// 		return ;
// 	}
// 	if (dup2(pipex->in_fd, STDIN_FILENO) < 0)
// 	{
// 		err_p("dup2 input failed");
// 		return ;
// 	}
// 	if (dup2(pipex->out_fd, STDIN_FILENO) < 0)
// 	{
// 		err_p("dup2 input failed");
// 		return ;
// 	}
// 	ft_close_fd(pipex->in_fd, pipex->out_fd);
// 	if (execve(pipex->cmd_paths[0], pipex->cmd_args[0], env) < 0)
// 	{
// 		perror("execeve failed");
// 		ft_printf("Failed to execute command: %s\n", pipex->cmd_paths[0]);
// 	}
// 	ft_printf("Error: Command execution failed\n");
// }

static void	ft_fork(pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
	{
		err_p("Couldn't Fork");
		exit(1);
	}
}
int	 ft_exec(t_pipex *pipex, int pipe_fd[], int i)
{
	pid_t	pid;

	ft_fork(&pid);
	if (pid == 0)
	{
		close(pipe_fd[1]);
		if (pipex->in_fd != STDIN_FILENO)
		{
			dup2(pipex->in_fd, STDERR_FILENO);
			close(pipex->in_fd);
			return -1;
		}
		dup2(pipe_fd[0], STDOUT_FILENO);
		close(pipe_fd[0]);
		if (execve(pipex->cmd_paths[i], pipex->cmd_args[i], NULL) < 0)
		{
			err_p("Execve Failed");
			exit(EXIT_FAILURE);
			return -1;
		}
	}
	else
	{
		close(pipe_fd[0]);
		if (pipex->in_fd != STDERR_FILENO)
			close(pipex->in_fd);
		pipex->in_fd = pipe_fd[1];
	}
	return 1;
}
