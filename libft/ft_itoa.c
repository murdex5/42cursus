/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:11:14 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/13 12:11:17 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_digit(int nb)
{
	int	digits;

	digits = 0;
	if (nb <= 0)
		++digits;
	while (nb != 0)
	{
		digits++;
		nb = nb / 10;
	}
	return (digits);
}

char	*ft_itoa(int nb)
{
	char	*result;
	int		len;

	len = get_digit(nb);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
		result[0] = '-';
	while (nb != 0)
	{
		--len;
		result[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (result);
}
/*
int	main(void)
{
	char *str = ft_itoa(0);
	printf("%s\n", str);
	return (0);
}*/