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

char	***ft_parse_cmds(int argc, char **argv, t_pipex *pipex, char *envp[])
{
	char	***cmds;
	char	**paths;
	int		i;
	int		l;

	paths = ft_get_path(envp);
	cmds = malloc(sizeof(char **) + (argc - 2 + 1));
	l = 1;
	if (pipex->here_doc == TRUE)
		l = 2;
	if (!cmds)
		return (NULL);
	i = l;
	while (i < argc - l)
	{
		
	}
}

char	***ft_parse_args(int argc, char **argv, t_pipex *pipex)
{
	char	***args;
	int		i;
	int		l;

	l = 1;
	if (!pipex)
		return (NULL);
	args = malloc(sizeof(char **) * argc);
	if (!args)
		return (NULL);
	if (pipex->here_doc == TRUE)
		l = 2;
	i = l;
	while (i < argc - l)
	{
		args[i - l] = ft_split(argv[i], ' ');
		if (!args[i - l])
			return (free_arr(args, i), NULL);
		i++;
	}
	args[i - l] = NULL;
	return (args);
}
