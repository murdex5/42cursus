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

static int	issep(char const s, char const c)
{
	if (s == c)
	{
		return (1);
	}
	return (0);
}

static int	count_words(char const *s, char const c)
{
	size_t	i;
	int		words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (!issep(s[i], c))
		{
			while (!issep(s[i], c))
				i++;
			words++;
		}
		i++;
	}
	return (words);
}

static void	split_words(char const *s, char const c, char **strarr)
{
	size_t	i;
	size_t	index;
	size_t	start;
	size_t	len;

	i = 0;
	index = 0;
	while (s[i] != '\0')
	{
		if (!issep(s[i], c))
		{
			start = i;
			while (!issep(s[i], c) && s[i])
				i++;
			len = i - start;
			strarr[index] = malloc(sizeof(char) * (len + 1));
			if (!strarr[index])
				return ;
			ft_strlcpy(strarr[index], &s[start], len);
			strarr[index][len + 1] = '\0';
			index++;
		}
		i++;
	}
	strarr[index] = NULL;
}

char	**ft_split(char const *s, char const c)
{
	char	**strarr;
	int		words_len;

	if (!s || !c)
		return (NULL);
	words_len = count_words(s, c);
	strarr = malloc(sizeof(char *) * (words_len + 1));
	if (!strarr)
		return (NULL);
	split_words(s, c, strarr);
	return (strarr);
}

/*
int	main(void)
{
	char *str = "Hello World, how are you?";
	char charset = ' ';
	char **strarr;
	int i = 0;

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
