/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:15:22 by kadferna          #+#    #+#             */
/*   Updated: 2025/07/28 11:15:26 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_separator(char c)
{
	return (c == ' ');
}

int	count_words_shell(const char *s)
{
	int		count;
	char	quote_state;

	count = 0;
	quote_state = 0;
	while (*s)
	{
		while (*s && is_separator(*s))
			s++;
		if (*s)
			count++;
		while (*s && (!is_separator(*s) || quote_state))
		{
			if (!quote_state && (*s == '\'' || *s == '"'))
				quote_state = *s;
			else if (quote_state == *s)
				quote_state = 0;
			s++;
		}
	}
	return (count);
}

char	*get_next_word(const char **s)
{
	char		quote_state;
	const char	*start;
	int			len;
	char		*word;

	quote_state = 0;
	len = 0;
	while (**s && is_separator(**s))
		(*s)++;
	start = *s;
	while ((*s)[len] && (!is_separator((*s)[len]) || quote_state))
	{
		if (!quote_state && ((*s)[len] == '\'' || (*s)[len] == '"'))
			quote_state = (*s)[len];
		else if (quote_state == (*s)[len])
			quote_state = 0;
		len++;
	}
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	*s += len;
	return (word);
}

void	specify_tokens(t_token *token)
{
	t_token	*head;
	t_token	*next;

	head = token;
	while (token != NULL)
	{
		next = token->next;
		if (ft_strncmp(token->value, "|", ft_strlen(token->value)) == 0)
			token->type = TOKEN_PIPE;
		else if (ft_strncmp(token->value, "EOF", ft_strlen(token->value)) == 0)
			token->type = TOKEN_EOF;
		else if (ft_strncmp(token->value, ">", ft_strlen(token->value)) == 0)
			token->type = TOKEN_REDIR_IN;
		else if (ft_strncmp(token->value, "<", ft_strlen(token->value)) == 0)
			token->type = TOKEN_REDIR_OUT;
		else if (ft_strncmp(token->value, "<<", ft_strlen(token->value)) == 0)
			token->type = TOKEN_HEREDOC;
		else if (ft_strncmp(token->value, ">>", ft_strlen(token->value)) == 0)
			token->type = TOKEN_REDIR_APPEND;
		else
			token->type = TOKEN_WORD;
		token = next;
	}
	token = head;
}
