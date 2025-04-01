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
	char	**line;
	int		i;

	paths = get_path(envp);
	cmds = malloc(sizeof(char *) * ((argc - 2) + 1));
	if (!cmds)
		return (free_two_vals("Memory allocation for cmds failed", NULL, paths,
				0), NULL);
	i = 2;
	while (i < argc - 1)
	{
		line = ft_split(argv[i], ' ');
		cmds[i - 2] = get_exe(line[0], paths);
		if (!cmds)
			return (free_two_vals("Memory allocation for cmds failed", cmds,
					line, i - 2), NULL);
		free_cmd_path(line);
		i++;
	}
	free_cmd_path(paths);
	cmds[i - 2] = NULL;
	return (cmds);
}

t_pip	*populate_pip(int argc, char **argv, char *envp[])
{
	t_pip	*pip;

	pip = init_pip();
	if (!pip)
		return (std_errors("Failed to initialize pip"), NULL);
	pip->here_doc = check_here_doc(argv);
	if (!check_args(argc, argv, pip))
	{
		ft_clean_up(pip);
		return (std_errors("Checking args failed"), NULL);
	}
	pip->cmd_args = parse_args(argc, argv);
	if (!pip->cmd_args)
		return (std_errors("Failed to parse args"), NULL);
	pip->cmd_path = parse_paths(argc, argv, envp);
	if (!pip->cmd_path)
	{
		ft_clean_up(pip);
		return (std_errors("Failed to parse cmds"), NULL);
	}
	return (pip);
}
