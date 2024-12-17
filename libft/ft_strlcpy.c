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

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
/*
int	main(void)
{
	char *str = "Hello, World!";
	char *dest = malloc(sizeof(char) * 6); 
		// Allocate enough space for 5 characters + null terminator
	size_t len = 13;  // The length of the source string
	size_t i = ft_strlcpy(dest, str, len); 
		// Corrected the order of parameters for ft_strlcpy

	printf("%s %zu \n", dest, i); 
		// Output the copied string and the length of the source string
	free(dest);  // Free the allocated memory
   return (0);
}*/
