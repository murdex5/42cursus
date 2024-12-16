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
	char	*str;
	size_t	i;
	char	*sub;

	str = (char *)s;
	if (!s)
		return (NULL);
	sub_len = ft_strlen(&s[start]);
	sub = malloc(sizeof(char) * sub_len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (str[start] != '\0' && i < len)
	{
		sub[i++] = str[start++];
	}
	sub[i] = '\0';
	return (sub);
}
/*
int	main(void)
{
	char    *main = "Hello, World!";
	char    *test = ft_substr(main, 7, ft_strlen(main));
	printf("%s\n", test);
	free(test);
	return (0);
}
*/
