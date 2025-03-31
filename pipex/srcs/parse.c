/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:49:04 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/31 13:49:07 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_pip	*init_pip(void)
{
	t_pip	*pip;

	pip = malloc(sizeof(t_pip));
	if (!pip)
		return (NULL);
	pip->cmd_args = NULL;
	pip->cmd_count = 0;
	pip->cmd_path = NULL;
	pip->is_invalid_infile = FALSE;
	pip->here_doc = FALSE;
	reknew_fd(&pip->in_fd);
	reknew_fd(&pip->out_fd);
	return (pip);
}
