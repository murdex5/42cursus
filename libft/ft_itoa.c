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
	{
		++digits;
		nb = -nb;
	}
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

	if (nb == -2147483648)
		return ("-2147483648");
	len = get_digit(nb);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	while (nb != 0)
	{
		--len;
		result[len] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char *str = ft_itoa(-2147483648);
	printf("%s\n", str);
	return (0);
}*/