/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                     +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:32:09 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/01 15:32:48 by kadferna         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv)
{
	t_pip	*pip;

	if (!check_ac(argc))
		return (1);
	pip = init_pip();
	if (!pip)
		return (std_errors("Could not initialize the data type."), 1);
	pip->here_doc = check_here_doc(argv);
	if (!check_args(argc, argv, pip))
	{
		clean_up(pip);
		return (1);
	}
	// Execute commands here (you'll need to implement this part)
	// execute_commands(pip, argc, argv);
	if (pip->here_doc == TRUE)
		unlink(".here_doc_tmp");
	clean_up(pip);
	return (0);
}
// int	main(int argc, char *argv[])
// {
// 	char *line;
// 	char *limiter;
// 	int in_fd[2];

// 	in_fd[0] = open(".here_doc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	if (in_fd[0] < 0)
// 		perror("sdf");
// 	if (argc != 3)
// 		return (0);
// 	limiter = ft_strjoin(argv[2], "\n");
// 	if (!limiter)
// 		return (0);
// 	while (1)
// 	{
// 		line = get_next_line(0);
// 		if (!line)
// 			break ;
// 		if (ft_strcmp(line, limiter) == 0)
// 		{
// 			free(line);
// 			break ;
// 		}
// 		write(in_fd[0], line, ft_strlen(line));
//         free(line);
// 	}
// 	free(limiter);
// 	close(in_fd[0]);
// 	return (0);
// }