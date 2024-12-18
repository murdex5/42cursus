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
	size_t start;
	size_t index;

	start = 0;
	index = 0;
	while (*s)
	{
		while (!issep(*s, c))
			s++;
		start = 0;
		if (start > 0)
		{
			strarr[index] = malloc(sizeof(char) * (start + 1));
			if (!strarr[index])
			{
				free(strarr);
				return ;
			}
			ft_strlcpy(strarr[index], s, start + 1);
			index++;
			s += start;
		}
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
