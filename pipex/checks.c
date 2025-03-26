/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:07:24 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/26 13:07:27 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_bool	ft_check_here_doc(char **argv)
{
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
		return (TRUE);
	return (FALSE);
}

static int	open_here_doc(t_pipex *pipex, int argc, char **argv)
{
	char	*line;

	pipex->in_fd = open(".here_doc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->in_fd == -1)
		return (err_p("Here doc file creation failed"));
	while (1)
	{
        ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0
			&& line[ft_strlen(argv[2])] == '\n')
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, pipex->in_fd);
		free(line);
	}
	close(pipex->in_fd);
	pipex->in_fd = open(".here_doc_tmp", O_RDONLY);
	if (pipex->in_fd == -1)
		return (err_p("Here_doc reopen failed"));
	pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (1);
}

static int	open_reg_file(t_pipex *pipex, int argc, char **argv)
{
	pipex->in_fd = open(argv[1], O_RDONLY);
	if (pipex->in_fd == -1)
	{
		if (ft_strncmp(argv[1], "/dev/urandom", ft_strlen("/dev/urandom")) == 0)
		{
			pipex->in_fd = open("/dev/urandom", O_RDONLY);
			if (pipex->in_fd == -1)
				return (err_p("Cannot open /dev/urandom"));
		}
		else
		{
			pipex->is_invalid_infile = TRUE;
            ft_putstr_fd("pipex: ", 2);
            ft_putstr_fd(argv[1], 2);
            ft_putstr_fd(": No such file or directory\n", 2);
		}
	}
	pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (1);
}

int	ft_check_args(int argc, char **argv, t_pipex *pipex)
{
	if (!pipex)
		return (1);
	if (pipex->here_doc == TRUE)
	{
		if (!open_here_doc(pipex, argc, argv))
			return (0);
	}
	else
	{
		if (!open_reg_file(pipex, argc, argv))
			return (0);
	}
	if (pipex->out_fd == -1)
		return (err_p("Output file error"));
    if (pipex->here_doc == TRUE)
        unlink(".here_doc_tmp");
	return (1);
}
