/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:14:36 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/11 11:29:05 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	c;
	unsigned char	*str;

	i = 0;
	c = '\0';
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
}
/*
int	main(void)
{
	char	*str = "Hello, World!";
	ft_bzero(str, (size_t)strlen(str));
	printf("%s \n", str);
	return (0);
}*/
