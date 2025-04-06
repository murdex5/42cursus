/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:32:11 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/04 14:32:12 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_strs(char *str1, char *str2)
{
	if (ft_strncmp(str1, str2, ft_strlen(str1)) == 0)
	{
		free(str2);
		return (0);
	}
	return (1);
}

int	get_command_count(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != NULL)
		i++;
	return (i);
}

int	count_commands(char ***cmd_args)
{
	int	count;

	count = 0;
	if (!cmd_args)
		return (0);
	while (cmd_args[count] != NULL)
		count++;
	return (count);
}

void	ft_close_close(int fd1, int fd2, int fd3, int fd4)
{
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
}
