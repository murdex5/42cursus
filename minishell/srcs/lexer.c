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
int	is_separator(char c, char c1, char c3) 
            return (c == c1 || c == c3);

static void	update_counts(char c, char separators[2], char c2, int *counts)
{
	if (c == c2)
	{
		counts[1] = !counts[1];
		if (!counts[1])
			counts[0]++;
	}
	else
	{
		if (!counts[1])
		{
			if (is_separator(c, separators[0], separators[1]))
				counts[2] = 0;
			else if (!counts[2])
			{
				counts[2] = 1;
				counts[0]++;
			}
		}
	}
}
static int	free_on_error(char **result, int word_count)
{
	while (word_count > 0)
	{
		word_count--;
		free(result[word_count]);
	}
	return (0);
}

static int	ft_split_words(char **result, char const *s, char seps[3])
{
	int	i;
	int	word_index;
	int	word_start;

	i = 0;
	word_index = 0;
	word_start = 0;
	while (s[i])
	{
		if (is_separator(s[i], seps[0], seps[1], seps[2]))
			word_start = i + 1;
		if (!is_separator(s[i], seps[0], seps[1], seps[2]) && is_separator(s[i
				+ 1], seps[0], seps[1], seps[2]))
		{
			result[word_index] = malloc(sizeof(char) * (i - word_start + 2));
			if (!result[word_index])
				return (free_on_error(result, word_index));
			ft_strlcpy(result[word_index], (s + word_start), i - word_start
				+ 2);
			word_index++;
		}
		i++;
	}
	result[word_index] = NULL;
	return (1);
}

int	numwords(char const *s, char c1, char c2, char c3)
{
	int		i;
	int		counts[3];
	char	separators[2];

	i = 0;
	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	separators[0] = c1;
	separators[1] = c3;
	while (s[i])
	{
		update_counts(s[i], separators, c2, counts);
		i++;
	}
	return (counts[0]);
}

char	**construct_tokens(char *line)
{
	char	**tokens;
	if (!line)
		return (NULL);
	tokens = malloc(sizeof(char *) * numwords(line, ' ', '"', 55) + 1);
	if (!tokens)
		return (NULL);
    if (!ft_split_words(tokens, line, [' ', '"', 55]))
        return (NULL);
	return (tokens);
}
