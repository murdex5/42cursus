/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:20:20 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/26 10:20:22 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_path(char **env)
{
	char	**paths;

	while (*env)
	{
		if (ft_strncmp(*env, "PATH", 4) == 0)
			break ;
		env++;
	}
	paths = ft_split(*env + 5, ':');
	return (paths);
}

char	*ft_get_exe(char *cmd, char **paths)
{
	char	*path;

	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		path = ft_strjoin(path, cmd);
		if (access(path, X_OK) == 0)
			return (path);
		paths++;
	}
	ft_no_exec(path);
	return (NULL);
}

void	ft_close_fd(int in_fd, int out_fd)
{
	if (in_fd > 0 && out_fd > 0)
	{
		close(in_fd);
		close(out_fd);
	}
}

void	reknew_pipe(int pip1, int pip2)
{
	close(pip1);
	close(pip2);
	pipe(pip1);
	pipe(pip2);
}

void	ft_new_p_fork(t_pipex *pipex, char **env)
{
	int pid;

	pid = fork();
	if (pid < 0)
		ft_pipex_err("Error when forking (1).");
	if (pid == 0)
	{
		ft_close_fd(pipex->in_fd, pipex->out_fd);
		ft_exec(pipex, env);
	}
	reknew_pipe(pipex->in_fd, pipex->out_fd);
}