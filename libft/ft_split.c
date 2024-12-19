/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:08:37 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/12 19:08:42 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

static size_t	count_words(char const *s, char const c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i + 1] != c)
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}
static int	split_words(char const *s, char const c, char **strarr, size_t word)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			strarr[word] = malloc(sizeof(char) * (i - start) + 1);
			if (!strarr[word])
			{
				while (word > 0)
				{
					free(strarr[word--]);
				}
				return (0);
			}
			ft_memcpy(strarr[word], &s[start], i - start + 1);
			word++;
		}
		i++;
	}
	strarr[word] = NULL;
	return (1);
}

char	**ft_split(char const *s, char const c)
{
	char	**strarr;
	size_t	word_len;
	size_t	words;

	if (!s || !c)
		return (NULL);
	words = 0;
	word_len = count_words(s, c);
	strarr = malloc(sizeof(char *) * word_len + 1);
	if (!strarr)
		return (NULL);
	if (split_words(s, c, strarr, words) == 0)
		return (NULL);
	return (strarr);
}
/*
int	main(void)
{
	//char *str = "                  olol";
	char	*str = "Hello world how are you";
	char charset = ' ';
	char **strarr;
	int i = 0;

	//printf("%d\n", count_words(str, charset));
	strarr = ft_split(str, charset);
	while (strarr[i] != NULL)
	{
		printf("%s\n", strarr[i]);
		// printf("%d\n", i);
		i++;
	}
	free(strarr);
	return (0);
}*/
