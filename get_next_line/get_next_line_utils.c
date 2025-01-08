/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:39:32 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/08 11:39:34 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}

char	*ft_strdup(const char *s)
{
	char *temp;
	size_t str_len;
	size_t i;

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
