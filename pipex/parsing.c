/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:20:07 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/26 10:20:09 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*ft_init_pipex(void)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	pipex->in_fd = 0;
	pipex->out_fd = 0;
	pipex->cmd_args = NULL;
	pipex->cmd_count = 0;
	pipex->cmd_paths = NULL;
	pipex->here_doc = FALSE;
	pipex->is_invalid_infile = FALSE;
	return (pipex);
}
