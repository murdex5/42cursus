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
	pip->env = NULL;
	pip->is_invalid_infile = FALSE;
	pip->here_doc = FALSE;
	return (pip);
}

char	***parse_args(int argc, char **argv, int offset)
{
	char	***args;
	int		i;

	args = ft_calloc(argc - 2, sizeof(char **));
	if (!args)
		return (std_errors("Could not allocate memory for arggs"), NULL);
	i = offset;
	while (i < argc - 1)
	{
		args[i - offset] = ft_split(argv[i], ' ');
		if (!args[i - offset])
		{
			free_arr_arr(args, i - offset);
			return (NULL);
		}
		i++;
	}
	args[i - offset] = NULL;
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

char	**parse_paths(char ***cmd_args, char *envp[])
{
	char	**paths;
	char	**exec_paths;
	int		i;

	paths = get_path(envp);
	if (!paths)
		return (std_errors("Could not get PATH"), NULL);
	exec_paths = ft_calloc(count_commands(cmd_args) + 1, sizeof(char *));
	if (!exec_paths)
		return (free_if("Memory allocation faild", paths, NULL), NULL);
	i = 0;
	while (cmd_args[i])
	{
		exec_paths[i] = get_exe(cmd_args[i][0], paths);
		if (!exec_paths[i])
		{
			free_cmd_path(paths);
			free_cmd_path(exec_paths);
			return (NULL);
		}
		i++;
	}
	free_cmd_path(paths);
	return (exec_paths);
}

t_pip	*populate_pip(int fd[2], int argc, char **argv, char *envp[])
{
	t_pip	*pip;
	int		offset;
	t_bool	here_docd;

	here_docd = check_here_doc(argv);
	offset = 2;
	if (!check_args(fd, argc, argv, here_docd))
		return (std_error_free(fd, NULL, "Checking args failed"), NULL);
	pip = init_pip();
	if (!pip)
		return (std_error_free(fd, pip, "Failed to initialize pip"), NULL);
	pip->here_doc = here_docd;
	if (pip->here_doc == TRUE)
		offset = 3;
	pip->cmd_args = parse_args(argc, argv, offset);
	if (!pip->cmd_args)
		return (std_errors("Failed to parse args"), NULL);
	pip->cmd_path = parse_paths(pip->cmd_args, envp);
	if (!pip->cmd_path)
		return (std_error_free(fd, pip, "Failed to parse cmds"), NULL);
	pip->cmd_count = get_command_count(pip->cmd_path);
	pip->env = envp;
	return (pip);
}
