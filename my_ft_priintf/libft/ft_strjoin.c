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
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!dest)
		return (NULL);
	ft_memmove(dest, s1, len1);
	ft_memmove(dest + len1, s2, len2);
	dest[len1 + len2] = '\0';
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