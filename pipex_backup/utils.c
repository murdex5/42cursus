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

void	ft_write_fd(char *name, int fd_in, t_bool hd)
{
	int		fd_out;
	int		b_read;
	char	buff[1];

	if (hd == TRUE)
		fd_out = open(name, O_RDWR | O_CREAT | O_APPEND, 00777);
	else
	{
		if (access(name, F_OK) == 0)
			unlink(name);
		fd_out = open(name, O_WRONLY | O_CREAT, 00777);
	}
	if (fd_in < 0)
		err_p("ft_write fd_out error.");
	if (fd_in < 0)
		err_p("ft_write fd_in error.");
	b_read = read(fd_in, &buff, sizeof(char));
	while (b_read > 0)
	{
		write(fd_out, &buff, 1);
		b_read = read(fd_in, &buff, sizeof(char));
	}
}

void	ft_wait(int i)
{
	int status;

	while (i-- > 0)
		wait(&status);
}