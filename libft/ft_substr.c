/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:08:55 by malshapraboth     #+#    #+#             */
/*   Updated: 2024/12/12 14:08:58 by malshapraboth    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sub_len;
	size_t	str_len;
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (NULL);
	sub_len = str_len - start;
	if (sub_len > len)
		sub_len = len;
	sub = (char *)malloc(sizeof(char) * (sub_len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
int	main(void)
{
	char	*main;
	char	*test;

	main = "Hello, World!";
	test = ft_substr(main, 7, ft_strlen(main));
	printf("%s\n", test);
	free(test);
	return (0);
}
*/
