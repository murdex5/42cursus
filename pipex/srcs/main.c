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
	// Execute commands here (you'll need to implement this part)
	// execute_commands(pip, argc, argv);
	if (pip->here_doc == TRUE)
		unlink(".here_doc_tmp");
	close_fd(pip->in_fd[0], pip->out_fd[0]);
	ft_clean_up(pip);
	return (0);
}
