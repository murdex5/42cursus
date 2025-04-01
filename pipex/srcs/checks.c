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

t_bool	check_here_doc(char **argv)
{
	if (argv[1] && ft_strncmp("here_doc", argv[1], ft_strlen(argv[1])) == 0)
		return (TRUE);
	return (FALSE);
}

// static int	compare_strs(char *str1, char *str2)
// {
// 	int	i;

// 	if (!str1 || !str2)
// 		return (1);
// 	i = ft_strcmp(str1, str2);
// 	return (i);
// }
static int	open_here_doc(int argc, char **argv, t_pip *pip)
{
	char	*line;

	pip->in_fd[0] = open(".here_doc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pip->in_fd[0] < 0)
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
		ft_putstr_fd(line, pip->in_fd[0]);
		free(line);
	}
	pip->out_fd[0] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (pip->out_fd[0] < 0)
        return (perror("Failed to reopen .here_doc_tmp"), 0);
    return (1);
}

static int	open_reguar(t_pip *pip, int argc, char **argv)
{
	pip->in_fd[0] = open(argv[1], O_RDONLY);
	if (pip->in_fd[0] == -1)
	{
		if (ft_strncmp(argv[1], "/dev/urandom", ft_strlen("/dev/urandom")) == 0)
		{
			pip->in_fd[0] = open("/dev/urandom", O_RDONLY);
			if (pip->in_fd[0] == -1)
				return (err_p("Cannot open /dev/urandom"));
		}
		else
		{
			pip->is_invalid_infile = TRUE;
			ft_putstr_fd("pipex: ", 2);
			ft_putstr_fd(argv[1], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
		}
	}
	pip->out_fd[0] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (1);
}

int	check_args(int argc, char **argv, t_pip *pip)
{
	if (!pip)
		return (0);
	if (pip->here_doc == TRUE)
	{
		if (!open_here_doc(argc, argv, pip))
			return (0);
	}
	else
	{
		if (!open_reguar(pip, argc, argv))
			return (0);
	}
	if (pip->out_fd[0] == -1)
		return (err_p("Output file error"));
	if (pip->here_doc == TRUE)
		unlink(".here_doc_tmp");
	return (1);
}
