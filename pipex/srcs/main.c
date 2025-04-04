/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:47:28 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/01 15:47:32 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char *envp[])
{
	t_pip	*pip;
	int		status;
	int		i;
	int		fd[2];

	if (!check_ac(argc))
		return (EXIT_FAILURE);
	status = 0;
	i = 0;
	pip = populate_pip(fd, argc, argv, envp);
	if (!pip)
		return (EXIT_FAILURE);
	while (pip->cmd_path[i] && pip->cmd_count > i)
	{
		if (ft_exec(fd, pip, pip->cmd_path[i], envp) == -1)
		{
			status = EXIT_FAILURE;
			break ;
		}
		i++;
	}
	if (pip->here_doc == TRUE)
		unlink(".here_doc_tmp");
	ft_clean_up(fd, pip);
	return (status);
}
