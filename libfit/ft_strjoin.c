/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:12:46 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/11 17:12:50 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	ft_memmove(dest, s1, ft_strlen(s1));
	ft_memmove(dest + ft_strlen(s1), s2, ft_strlen(s2));
	dest[len + 1] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char    *str1 = "Hello ";
	char    *str2 = "wolrd!";
	char *full = ft_strjoin(str1, str2);
	printf("%s\n", full);
	return (0);
}*/