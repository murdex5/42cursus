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
	int		i;
	int		j;

	i = 2;
	if (!pipex)
		return (NULL);
	cmds = malloc(sizeof(char *) * (argc - 2 + 1));
	if (!cmds)
		return (NULL);
	while (i < argc)
	{
		j = 0;
		while (envp[j] != NULL)
		{
			if (ft_strnstr(envp[j], argv[i], ft_strlen(argv[i])))
				cmds[i - 2][0] = ft_strdup(ft_strnstr(envp[j], argv[i],
							ft_strlen(argv[i])));
			j++;
		}
		i++;
	}
	cmds[i] = NULL;
	return (cmds);
}

char	***ft_parse_args(int argc, char **argv, t_pipex *pipex)
{
	char	***args;
	int		i;

	i = 1;
	if (!pipex)
		return (NULL);
	args = malloc(sizeof(char **) * argc);
	if (!args)
		return (NULL);
	while (i < argc - 1)
	{
		args[i - 1] = ft_split(argv[i], ' ');
		if (!args[i - 1])
			return (free_arr(args, i), NULL);
		i++;
	}
	args[i - 1] = NULL;
	return (args);
}
