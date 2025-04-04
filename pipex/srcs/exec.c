/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:30:36 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/02 14:30:38 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	ft_fork(pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("forking failed");
		return (0);
	}
	return (1);
}

static void	first_child(int fd[2], char *path, int in_fd, t_pip *pip)
{
	close(fd[0]);
	dup2(in_fd, STDIN_FILENO);
	close(in_fd);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execve(path, pip->cmd_args[0], pip->env);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

static void	second_child(int fd[2], int outfile, t_pip *pip, char *path)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	execve(path, pip->cmd_args[1], pip->env);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

static int	ft_children_exited(int status1, int status2)
{
	if (WIFEXITED(status2))
	{
		if (WEXITSTATUS(status2) != 0)
			return (WEXITSTATUS(status2));
		if (WIFEXITED(status1) && WEXITSTATUS(status1) != 0)
			return (WEXITSTATUS(status1));
	}
	else if (WIFSIGNALED(status2))
	{
		return (128 + WTERMSIG(status2));
	}
	if (WIFSIGNALED(status1))
		return (128 + WTERMSIG(status1));
	return (0);
}

int	ft_exec(int fd[2], t_pip *pip, char **path, int out_fd[2])
{
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;

	if (pipe(fd) == -1)
		return (perror("pipe failed"), EXIT_FAILURE);
	if (!ft_fork(&pid1))
		return (close_fd(fd[0], out_fd[1]), EXIT_FAILURE);
	if (pid1 == 0)
		first_child(fd, path[0], out_fd[0], pip);
	if (!ft_fork(&pid2))
	{
		kill(pid1, SIGTERM);
		close_fd(fd[0], out_fd[1]);
		waitpid(pid1, NULL, 0);
		return (EXIT_FAILURE);
	}
	if (pid2 == 0)
		second_child(fd, out_fd[1], pip, path[1]);
	close_fd(fd[0], fd[1]);
	close_fd(out_fd[0], out_fd[1]);
	waitpid(pid2, &status2, 0);
	waitpid(pid1, &status1, 0);
	return (ft_children_exited(status1, status2));
}
