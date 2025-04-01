/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                     +#+  +:+
	+#+        */
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
char	***parse_args(int argc, char **argv)
{
	char	***args;
	int		i;

	args = malloc(sizeof(char **) * ((argc - 2) + 1));
	if (!args)
		return (std_errors("Could not allocate memory for arggs"), NULL);
	i = 2;
	while (i < argc - 1)
	{
		args[i - 2] = ft_split(argv[i], ' ');
		if (!args[i - 2])
			free_arr_arr(args, i - 2);
		i++;
	}
	args[i - 2] = NULL;
	return (args);
}

char	**parse_paths(int argc, char **argv, char *envp[])
{
	char	**cmds;
	char	**paths;
	int		i;

	paths = get_path(envp);
	if (!paths)
		return (std_errors("Memory allocation for paths failed"), NULL);
	cmds = malloc(sizeof(char *) * ((argc - 2) + 1));
	if (!cmds)
	{
		free_cmd_path(paths);
		return (std_errors("Memory allocation for cmds failed"), NULL);
	}
	i = 2;
	while (i < argc - 1)
	{
		cmds[i - 1] = get_exe(ft_split(argv[i], ' ')[0], paths);
		if (!cmds)
			return (free_arr(cmds, i - 2), NULL);
		i++;
	}
	cmds[i - 2] = NULL;
	return (cmds);
}
