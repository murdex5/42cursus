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

static int	count_words(char const *s, char const c)
{
	size_t	i;
	int		words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] == c))
		{
			while (!(s[i] == c))
				i++;
			words++;
		}
		i++;
	}
	return (words);
}
static int	split_words(char const *s, char const c, char **strarr, int word)
{
	size_t	start;
	size_t	end;

	end = 0;
	start = 0;
	while (s[end])
	{
		if (s[end] == c || s[end] == 0)
			start = end + 1;
		if (s[end] != c && (s[end + 1] == c || s[end] == 0))
		{
			strarr[word] = malloc(sizeof(char) * (end - start + 2));
			if (!strarr)
			{
				while (word++)
					free(strarr[word]);
				return (0);
			}
			ft_strlcpy(strarr[word], (s + start), end - start + 2);
			word++;
		}
		end++;
	}
	strarr[word] = NULL;
	return (1);
}

char	**ft_split(char const *s, char const c)
{
	char	**strarr;

	if (!s)
		return (NULL);
	strarr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!strarr)
		return (NULL);
	if (!split_words(s, c, strarr, 0))
		return (NULL);
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
