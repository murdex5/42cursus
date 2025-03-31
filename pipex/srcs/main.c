/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:18:53 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/31 10:18:58 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../pipex.h"

int main(int argc, char **argv, char *envp[])
{
    int pipe1[2];
    int pipe2[2];
    int here_doc;
    if (!check_ac(argc))
        return (1);
    reknew_pipe(&pipe1);
    reknew_pipe(&pipe2);
    ft_printf("%s %s\n", argv[1], argv[2]);
    here_doc = check_here_doc(argv, &pipe2);
    ft_printf("%s %s\n", argv[0], envp[0]);
    if (here_doc)
        ft_printf("Hello World!\n");
    close_fd(pipe1[0], pipe1[1]);
    close_fd(pipe2[0], pipe2[1]);
    return (0);
}

// int main(int argc, char **argv)
// {
//     int fd = 4;
//     if (!check_ac(argc))
//          return (1);
//     read_here_doc(argv[2], fd);
//     close(fd);
//     return(1);
// }