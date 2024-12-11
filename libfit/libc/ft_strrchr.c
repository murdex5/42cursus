/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:56:39 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/11 10:16:23 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	enc;
	int	index;

	i = 0;
	enc = 0;
	index = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] == (unsigned char)c)
		{
			index = i;
			enc++;
		}
		i++;
	}
	if (enc < 1)
		return ((char *)&str[i]);
	return ((char *)&str[index]);
}
/*
#include <stdio.h>
int main(void)
{
	char *str = "Hello, World";
	int	c = 'l';
	printf("%s\n", ft_strrchr(str, c));
	return 0;
}*/
