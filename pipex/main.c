/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:46:39 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/26 09:46:41 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_pipex	*pipex;
	int		i;
	int		j;

	if (argc < 5)
		return (1);
	pipex = ft_init_pipex();
	if (!pipex)
		return (1);
	pipex->cmd_args = ft_parse_args(argc, argv, pipex);
	if (!pipex->cmd_args)
	{
        ft_printf("%d\n", j);
		free(pipex);
		return (1);
	}
	return (0);
}
