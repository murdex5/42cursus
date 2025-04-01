/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                     +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:42:42 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/01 15:42:49 by kadferna         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	free_args(char ***str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != NULL)
		{
			if (str[i][j])
				free(str[i][j]);
			j++;
		}
		free(str[i]);
		i++;
	}
	free(str);
}

static void	free_cmd_path(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
}

void	clean_up(t_pip *pip)
{
	if (!pip)
		return ;
	if (pip->cmd_args)
		free_args(pip->cmd_args);
	if (pip->cmd_path)
		free_cmd_path(pip->cmd_path);
	free(pip);
}
