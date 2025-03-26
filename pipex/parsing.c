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

int ft_check_args(int argc, char **argv, t_pipex *pipex)
{
	if (!pipex)
		return (1);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		pipex->here_doc = TRUE;
		pipex->in_fd = open(".here_doc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (pipex->in_fd < 0)
			return (err_p("Open"));
	}
	
}

char	***ft_parse_args(int argc, char **argv, t_pipex *pipex)
{
	char	***args;
	int		i;

	i = 1;
	if (!pipex)
		return (0);
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
