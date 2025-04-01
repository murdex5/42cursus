/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:46:44 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/01 15:46:46 by kadferna         ###   ########.fr       */
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
void	free_arr_arr(char ***str, int i)
{
	int	j;

	while (i > 0)
	{
		j = 0;
		while (str[i][j] != NULL)
		{
			if (str[i][j])
				free(str[i][j]);
			j++;
		}
		free(str[i]);
		i--;
	}
	std_errors("Failed to allocate memory for args");
	free(str);
}

void	free_cmd_path(char **str)
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

void	free_arr(char **str, int i)
{
	while (i > 0)
	{
		if (str[i])
			free(str[i]);
		i--;
	}
	free(str);
}

void	ft_clean_up(t_pip *pip)
{
	if (!pip)
		return ;
	if (pip->cmd_args)
		free_args(pip->cmd_args);
	if (pip->cmd_path)
		free_cmd_path(pip->cmd_path);
	free(pip);
}
