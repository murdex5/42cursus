/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:47:51 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/01 15:47:54 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_ac(int ac)
{
	if (ac < 5)
		return (std_errors("./pipex infile cmd1 cmd2 outfile"), 0);
	return (1);
}

int	get_command_count(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != NULL)
		i++;
	return (i);
}

t_bool	check_here_doc(char **argv)
{
	if (argv[1] && ft_strncmp("here_doc", argv[1], ft_strlen(argv[1])) == 0)
		return (TRUE);
	return (FALSE);
}

static int	open_here_doc(int argc, char **argv, t_pip *pip)
{
	char	*line;

	pip->fd[0] = open(".here_doc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pip->fd[0] < 0)
		return (perror("Failed to open .here_doc_tmp"), 0);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return (std_errors("Memory allocation for line failed"), 0);
		if (ft_strncmp(argv[2], line, ft_strlen(argv[2])) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, pip->fd[0]);
		free(line);
	}
	close(pip->fd[0]);
	pip->fd[0] = open(".here_doc_tmp", O_RDONLY);
	if (pip->fd[0] < 0)
		return (perror("Failed to reopen .here_doc_tmp"), 0);
	pip->fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (pip->fd[1] < 0)
		return (perror("Failed to reopen .here_doc_tmp"), 0);
	return (1);
}

static int	open_regular(t_pip *pip, int argc, char **argv)
{
	if (ft_strcmp(argv[1], "/dev/urandom") == 0)
	{
		pip->fd[0] = open("/dev/urandom", O_RDONLY);
		if (pip->fd[0] == -1)
			return (err_p("Cannot open /dev/urandom"));
	}
	else
	{
		pip->fd[0] = open(argv[1], O_RDONLY);
		if (pip->fd[0] == -1)
		{
			pip->is_invalid_infile = TRUE;
			ft_putstr_fd("pipex: ", STDERR_FILENO);
			perror(argv[1]);
		}
	}
	pip->fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pip->fd[1] == -1)
	{
		if (pip->fd[0] != -1)
			close(pip->fd[0]);
		return (perror(argv[argc - 1]), 0);
	}
	return (1);
}

int	check_args(int argc, char **argv, t_pip *pip)
{
	if (!pip)
		return (err_p("Null pipex structure"));
	// Argument count validation
	if (pip->here_doc == TRUE && argc < 6)
		return (err_p("here_doc requires 6 arguments"));
	if (pip->here_doc == FALSE && argc < 5)
		return (err_p("Too few arguments"));
	// File opening
	if (pip->here_doc == TRUE)
	{
		if (!open_here_doc(argc, argv, pip))
			return (0);
	}
	else
	{
		if (!open_regular(pip, argc, argv))
			return (0);
	}
	// Final checks
	if (pip->fd[1] == -1)
		return (err_p("Output file error"));
	return (1);
}
