/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:28:51 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/31 10:29:01 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_ac(int ac)
{
	if (ac < 5)
	{
		ft_putstr_fd("Pipex: ./pipex infile cmd1 cmd2 outfile \n",
			STDERR_FILENO);
		return (0);
	}
	return (1);
}

void	read_here_doc(char *limiter, int out_fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			return ;
		}
		ft_putstr_fd(line, out_fd);
		free(line);
	}
}

void	ft_write(char **argv, char *name, int in_fd, int out_fd)
{
	char	buf[1];
	int		bytes_read;

	if (ft_strncmp("here_doc", argv[1], 8) == 0)
		out_fd = open(name, O_RDONLY);
	else
	{
		ft_unlink(name);
		out_fd = open(name, O_CREAT | O_WRONLY, 0777);
		if (out_fd < 0)
			err_p("Could not create the file\n");
	}
	if (out_fd < 0)
		err_p("Could not open the file\n");
	bytes_read = read(in_fd, &buf, sizeof(char));
	while (bytes_read > 0)
	{
		write(out_fd, &buf, 1);
		bytes_read = read(in_fd, &buf, sizeof(char));
	}
}

int	check_here_doc(char **argv, int (*p)[2])
{
	int	fd_temp;

	if (ft_strncmp("here_doc", argv[1], ft_strlen("here_doc")) == 0)
	{
		fd_temp = open("here_doc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd_temp < 0)
			return (err_p("Couldn't find or create the file\n"), 0);
		read_here_doc(argv[2], fd_temp);
		ft_write(argv, argv[6], fd_temp, (*p)[1]);
	}
	else
	{
		fd_temp = open(argv[1], O_RDONLY);
		if (fd_temp < 0)
			return (err_p("Couldn't open the input file"), 0);
		(*p)[0] = fd_temp;
	}
	return (0);
}
