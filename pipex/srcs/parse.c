/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:24:35 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/01 15:24:35 by kadferna         ###   ########.ch       */
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
	return (pip);
}
