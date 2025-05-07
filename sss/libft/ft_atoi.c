/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/12/11 14:37:15 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/11 14:37:18 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"


static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	ft_isdiggit(int c)
{
	return (c >= '0' && c <= '9');
}

static void	skip_spaces(const char *nptr, int *i, int *sign)
{
	while (ft_isspace(nptr[(*i)]))
		(*i)++;
	if (nptr[(*i)] == '-' || nptr[(*i)] == '+')
	{
		if (nptr[(*i)] == '-')
			*sign = -1;
		(*i)++;
	}
}

int	ft_atoi(const char *nptr)
{
	int i;
	int sign;
	long result;
	int digit;

	i = 0;
	sign = 1;
	result = 0;
	skip_spaces(nptr, &i, &sign);
	while (ft_isdiggit(nptr[i]))
	{
		digit = nptr[i] - '0';
		if (sign == 1)
		{
			if (result > INT_MAX / 10 || (result == INT_MAX / 10
					&& digit > INT_MAX % 10))
				return (0);
		}
		if (result > 214748364L || (result == 214748364L && digit > 8))
			return (-1);
		result = result * 10 + digit;
		i++;
	}
	return ((int)(result * sign));
}
