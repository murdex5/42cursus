/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:02:12 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/11 11:02:15 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	if (s == NULL)
		return (NULL);
	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>

int	main(void) {
	char buffer[10];
	ft_memset(buffer, 9, sizeof(buffer));  // Sets all 10 bytes of 'buffer' to 0
	for(size_t i = 0; i < sizeof(buffer); i++)
		printf("%d ", buffer[i]);
	return (0);
}*/
