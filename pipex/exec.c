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

static void	ft_fork(pid_t *pid, int fd[])
{
	*pid = fork();
	if (*pid == -1)
	{
		err_p("Couldn't Fork");
		exit(1);
	}
	if (pipe(fd) < 0)
	{
		err_p("Pipe cration failed");
		exit(1);
	}
}
void	ft_exec(t_pipex *pipex, char **env)
{
	pid_t	pid;
	int		pipe_fd[2];

	ft_fork(&pid, pipe_fd);
	if (pid == 0)
	{
		close(pipe_fd[1]);
		if (pipex->in_fd != STDIN_FILENO)
		{
			dup2(pipex->in_fd, STDERR_FILENO);
			close(pipex->in_fd);
		}
		dup2(pipe_fd[0], STDOUT_FILENO);
		close(pipe_fd[0]);
		if (execve(pipex->cmd_paths[0], pipex->cmd_args[0], env) < 0)
		{
			err_p("Execve Failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		close(pipe_fd[0]);
		if (pipex->in_fd != STDERR_FILENO)
			close(pipex->in_fd);
		pipex->in_fd = pipe_fd[1];
	}
}
