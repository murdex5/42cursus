/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:32:23 by kadferna          #+#    #+#             */
/*   Updated: 2025/07/12 17:32:26 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static volatile sig_atomic_t	g_signal_recieved = 0;

void	signal_handler(int sig)
{
	g_signal_recieved = sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
int	main(char **envp)
{
	char				*line;
	struct sigaction	sa;
	char				**tokens;

	sa.sa_handler = signal_handler;
	if (!process_signals(&sa))
		exit(1);
	while (1)
	{
		if (g_signal_recieved)
			g_signal_recieved = 0;
		line = readline("minishell> ");
		if (line == NULL)
			return (ft_exit(line), 0);
		if (*line)
		{
			add_history(line);
			tokens = construct_tokens(line);
		}
		free(line);
	}
	free(line);
	free_tokens(tokens);
	return (0);
}
