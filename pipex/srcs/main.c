/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:39:33 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/31 13:39:34 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv)
{
	t_pip	*pip;

	if (!check_ac(argc))
		return (1);
	pip = init_pip();
	if (!pip)
		return (std_errors("Could not initialize the data type"), 1);
	pip->here_doc = check_here_doc(argv);
	close_fd(pip->in_fd[0], pip->in_fd[1]);
	close_fd(pip->out_fd[0], pip->out_fd[1]);
    ft_printf("Program finished successfully\n");
	return (0);
}
