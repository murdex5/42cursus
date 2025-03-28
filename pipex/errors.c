/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:59:00 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/26 11:59:03 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	err_p(char *err_type)
{
	perror("pipex");
	ft_printf("%s\n", err_type);
	return (0);
}

int	ft_no_exec(char *s)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(s, STDERR_FILENO);
	ft_putstr_fd(" : Command not found.", STDERR_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	exit(1);
}