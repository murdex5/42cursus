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

static void	first_child(char *path, t_pip *pip, char *envp[])
{
	close(pip->fd[0]);
	dup2(pip->fd[1], STDOUT_FILENO);
	close(pip->fd[1]);
	execve(path, pip->cmd_args[0], envp);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

static void	second_child(char *path, t_pip *pip, char *envp[])
{
	close(pip->fd[1]);
	dup2(pip->fd[0], STDIN_FILENO);
	close(pip->fd[0]);
	execve(path, pip->cmd_args[1], envp);
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

int	ft_exec(t_pip *pip, char *path, char *envp[])
{
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;

	if (pipe(pip->fd) == -1)
		return (perror("pipe failed"), EXIT_FAILURE);
	if (!ft_fork(&pid1))
		return (EXIT_FAILURE);
	if (pid1 == 0)
		first_child(path, pip, envp);
	if (!ft_fork(&pid2))
	{
		kill(pid1, SIGTERM);
		close_fd(pip->fd[0], pip->fd[1]);
		waitpid(pid1, NULL, 0);
		return (EXIT_FAILURE);
	}
	if (pid2 == 0)
		second_child(path, pip, envp);
	close_fd(pip->fd[0], pip->fd[1]);
	waitpid(pid2, &status2, 0);
	waitpid(pid1, &status1, 0);
	return (ft_children_exited(status1, status2));
}
