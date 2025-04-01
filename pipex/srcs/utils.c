/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                     +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:24:00 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/01 15:24:00 by kadferna         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_fd(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
void	reknew_fd(int (*p)[2])
{
	close_fd((*p)[0], (*p)[1]);
	pipe((*p));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char	*get_exe(char *cmd, char **paths)
{
	char	*path;
	char	*temp;

	if (!cmd || !paths)
		return (NULL);
	while (*paths)
	{
		temp = ft_strjoin(*paths, "/");
		if (!temp)
			return (NULL);
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (!path)
			return (NULL);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		paths++;
	}
	return (NULL);
}

char	**get_path(char *env[])
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

int	free_two_vals(char *msg, char **arr1, char **arr2, int i)
{
	if (arr1)
		free_arr(arr1, i - 2);
	if (arr2)
		free_cmd_path(arr2);
	std_errors(msg);
	free(msg);
	return (1);
}
