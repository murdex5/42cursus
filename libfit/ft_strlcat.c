/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:06:45 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/11 14:36:47 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	i;

	dest_len = 0;
	i = 0;
	while (dst[dest_len] != '\0' && dest_len < size)
		dest_len++;
	if (dest_len == size)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && dest_len + i < size - 1)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + ft_strlen(src));
}
/*
int	main(void)
{
	char	*src;
	char    dest[12] = "Hello";
	int		len;

	src = " world";
	len = ft_strlcat(dest, src, sizeof(dest));
	printf("%s \n", dest);
	return (0);
}
*/
