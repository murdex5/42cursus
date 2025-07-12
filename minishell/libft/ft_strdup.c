/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:31:02 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/11 15:31:05 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*temp;
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(s);
	if (!s)
		return (NULL);
	temp = malloc(sizeof(char) * (str_len + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
/*
int	main(void)
{
	char *str = "Hello";
	char *cop = ft_strdup(str);
	printf("%s \n", cop);
	return (0);
}*/