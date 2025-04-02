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

	if (!check_ac(argc))
		return (1);
	pip = populate_pip(argc, argv, envp);
	if (!pip)
		return (1);
	while (*pip->cmd_path)
	{
		ft_exec(pip, *pip->cmd_path, envp);
		pip->cmd_path++;
	}
	if (pip->here_doc == TRUE)
		unlink(".here_doc_tmp");
	ft_clean_up(pip);
	return (0);
}
