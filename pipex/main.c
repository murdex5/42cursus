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

int	get_arr_lenth(char ***str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != NULL)
	{
		i++;
	}
	return (i);
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipex	*pipex;
	int		i;

	if (argc < 5)
	{
		ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		ft_printf("   or: ./pipex here_doc DELIMITER cmd1 cmd2 .... cmdn file\n");
		;
		return (1);
	}
	pipex = ft_init_pipex();
	if (!pipex)
		return (1);
	pipex->here_doc = ft_check_here_doc(argv);
	if (!ft_check_args(argc, argv, pipex))
		return (1);
	pipex->cmd_args = ft_parse_args(argc, argv, pipex);
	if (!pipex->cmd_args)
	{
		free(pipex);
		return (1);
	}
	pipex->cmd_paths = ft_parse_cmds(argc, argv, envp);
	if (!pipex->cmd_paths)
	{
		// Free cmd_args before exiting
		free_ptr_arr(pipex->cmd_args, get_arr_lenth(pipex->cmd_args));
		free(pipex);
		return (1);
	}
	// Debug print (temporary)
	i = 0;
	ft_printf("Command paths:\n");
	while (pipex->cmd_paths && pipex->cmd_paths[i] != NULL)
	{
		ft_printf("%d: %s\n", i, pipex->cmd_paths[i]);
		i++;
	}
	// Here you would execute the actual pipex logic
	// ft_execute_pipex(pipex, envp);
	ft_cleanup(pipex);
	ft_printf("Program finished successfully\n");
	return (0);
}
