/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:12:56 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/09 17:19:07 by kadferna         ###   ########.fr       */
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

#include <stdio.h>
int main(void)
{
	char	*str = "Hello world";
	char	s = 'w';
	printf("%s\n", ft_strchr(str, s));
	return(0);
}
