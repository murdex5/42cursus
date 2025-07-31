/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:50:34 by kadferna          #+#    #+#             */
/*   Updated: 2025/07/16 16:50:38 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

extern t_token	*g_current_token;

t_redirect		*parse_redirection(void);

t_ast_node	*parse_command(t_token *tokens)
{
	t_list			*words;
	t_redirect		*redirections;
	t_ast_node		*node;
	t_redirect		*new_redir;
	t_command_node	*cmd_node;

	words = NULL;
	redirections = NULL;
	while (g_current_token->type == TOKEN_WORD
		|| is_redirection(g_current_token))
	{
		if (g_current_token->type == TOKEN_WORD)
		{
			ft_lstadd_back(&words, ft_lstnew(g_current_token->value));
			g_current_token = g_current_token->next;
		}
		else if (is_redirection(g_current_token))
		{
			new_redir = parse_redirection();
			if (!new_redir)
				return (ft_lstclear(&words, free), NULL);
		}
		add_redirection_to_list(&redirections, new_redir);
	}
	if (words)
	{
		cmd_node = malloc(sizeof(t_command_node));
		cmd_node->type = NODE_COMMAND;
		cmd_node->argv = convert_list_to_argv(words);
		cmd_node->redirections = redirections;
		ft_lstclear(&words, NULL);
		node = (t_ast_node *)cmd_node;
	}
	else if (redirections)
	{
		report_syntax_error("missing command", g_current_token);
		free_redirection_list(redirections);
		return (NULL);
	}
	else
		return (NULL);
	return (node);
}

t_ast_node	*parse_command_line(t_token *tokens)
{
	g_current_token = tokens;
	return (NULL);
}
