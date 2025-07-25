/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:22:02 by kadferna          #+#    #+#             */
/*   Updated: 2025/07/23 13:22:04 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_separator(char c)
{
	return (c == ' ');
}

static int	count_words_shell(const char *s)
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

static char	*get_next_word(const char **s)
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

char	**construct_tokens(char *line)
{
	char		**tokens;
	int			word_count;
	int			i;
	const char	*line_ptr;

	if (!line)
		return (NULL);
	line_ptr = line;
	word_count = count_words_shell(line_ptr);
	tokens = malloc(sizeof(char *) * (word_count + 1));
	if (!tokens)
		return (NULL);
	i = 0;
	line_ptr = line;
	while (i < word_count)
	{
		tokens[i] = get_next_word(&line_ptr);
		if (!tokens[i])
			return (free_on_error(tokens, i), NULL);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
