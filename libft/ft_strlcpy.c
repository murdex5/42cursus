/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:12:01 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/11 13:27:33 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	copy_len;

	if (size == 0)
		return (ft_strlen(src));
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	copy_len = src_len;
	if (copy_len > size - 1)
		copy_len = size - 1;
	i = 0;
	while (i < copy_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "coucou";
	char	dest[10]; ft_memset(dest, 'A', 10);
	size_t i = ft_strlcpy(dest, src, 1);
	printf("%s %zu", dest, i);
	return (0);
}*/
