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
	ft_bzero(pip, sizeof(t_pip));
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

	args = ft_calloc(argc - 2, sizeof(char **));
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

static void	free_if(char *msg, char **str1, char **str2)
{
	if (!str1 && str2)
		free_cmd_path(str2);
	else if (str1 && !str2)
		free_cmd_path(str1);
	else
		return ;
	std_errors(msg);
}

char	**parse_paths(int argc, char **argv, char *envp[], int offset)
{
	char	**cmds;
	char	**paths;
	char	**line;
	int		i;

	paths = get_path(envp);
	cmds = ft_calloc(argc - offset, sizeof(char *));
	if (!cmds || !paths)
		return (free_if("Memory allocation for cmds failed", cmds, paths),
			NULL);
	i = offset;
	while (i < argc - 1)
	{
		line = ft_split(argv[i], ' ');
		cmds[i - offset] = get_exe(line[0], paths);
		if (!cmds[i - offset])
			return (free_two_vals(cmds, line, i - offset, paths), NULL);
		free_cmd_path(line);
		i++;
	}
	free_cmd_path(paths);
	return (cmds);
}

t_pip	*populate_pip(int fd[2], int argc, char **argv, char *envp[])
{
	t_pip	*pip;
	int		offset;

	pip = init_pip();
	if (!pip)
		return (std_errors("Failed to initialize pip"), NULL);
	pip->here_doc = check_here_doc(argv);
	offset = 2;
	if (!check_args(fd, argc, argv, pip))
		return (std_error_free(fd, pip, "Checking args failed"), NULL);
	pip->cmd_args = parse_args(argc, argv);
	if (!pip->cmd_args)
		return (std_errors("Failed to parse args"), NULL);
	if (pip->here_doc == TRUE)
		offset = 3;
	pip->cmd_path = parse_paths(argc, argv, envp, offset);
	if (!pip->cmd_path)
		return (std_error_free(fd, pip, "Failed to parse cmds"), NULL);
	pip->cmd_count = get_command_count(pip->cmd_path);
	return (pip);
}
