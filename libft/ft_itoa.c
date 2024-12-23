/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:47:59 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/23 11:48:01 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	absolute(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static int	get_digits(int nb)
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

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	len = get_digits(nb);
	result = malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
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
