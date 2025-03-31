/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:10:28 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/26 11:10:30 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	free_ptr_arr(char ***str_arr, int i)
{
	int	j;

	while (i > 0)
	{
		j = 0;
		while (str_arr[i][j] != NULL)
		{
			if (str_arr[i][j])
				free(str_arr[i][j]);
			j++;
		}
		i--;
	}
	free(str_arr);
	return (1);
}

int	free_arr(char **str_arr, int i)
{
	while (i > 0)
	{
		if (str_arr[i])
			free(str_arr[i]);
		i--;
	}
	free(str_arr);
	return (1);
}

static void	clean_str_arr(char ***str)
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
		i++;
	}
}
void	ft_free_array(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
}

void	ft_cleanup(t_pipex *pipex)
{
	if (!pipex)
		return ;
	if (!pipex->cmd_args)
		clean_str_arr(pipex->cmd_args);
	if (!pipex->cmd_paths)
		ft_free_array(pipex->cmd_paths);
	free(pipex);
}