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

static char	*allocate_mem(int len, int nb)
{
	char	*str;

	if (nb == -2147483648)
	{
		str = malloc(sizeof(char) + 12);
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int nb)
{
	char	*result;
	int		len;

	len = get_digit(nb);
	if (nb == -2147483648)
		return (allocate_mem(len, nb));
	result = allocate_mem(len, nb);
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
#include <stdlib.h>

int	main(int ac, char **av)
{
	char *str = ft_itoa(atoi(av[1]));
	printf("%s\n", str);
	free(str);
	return (0);
}*/