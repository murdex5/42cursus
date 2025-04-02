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

void	ft_exec(t_pip *pip, char *path, char *envp[])
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == -1)
	{
		perror("forking failed");
	}
	if (pid1 == 0)
	{
		dup2(pip->fd[0], pip->fd[1]);
		execve(path, pip->cmd_args[0], envp);
	}
	pid2 = fork();
	if (pid1 == -1)
	{
		perror("forking failed");
	}
	if (pid2 == 0)
	{
		dup2(pip->fd[0], pip->fd[1]);
		execve(path, pip->cmd_args[0], envp);
	}
    close_fd(pip->fd[0], pip->fd[1]);
    std_errors("Execeve failed");
}
