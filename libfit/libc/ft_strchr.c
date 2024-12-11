/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:54:46 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/11 09:54:51 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[c] != '\0')
	{
		if (str[c] == i)
		{
			return (str[c]);
		}
		i++;
	}
	return ('\0');
}
/*
#include <stdio.h>
int main(void)
{
	char	*str = "Hello world";
	char	s = 'w';
	printf("%s\n", ft_strchr(str, s));
	return(0);
}*/
