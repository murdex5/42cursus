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


volatile sig_atomic_t	g_signal_recieved = 0;

void	signal_handler(int sig)
{
	g_signal_recieved = sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
int	main(void)
{
	char				*line;
	struct sigaction	sa;
	char				**tokens;
	int					i;

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
			printf("%s\n", line);
			tokens = construct_tokens(line);

			break ;
		}
		free(line);
	}
	i = 0;
	while (tokens[i] != NULL)
	{
		printf("%s\n", tokens[i]);
		i++;
	}
	free(line);
	free_tokens(tokens);
	return (0);
}
