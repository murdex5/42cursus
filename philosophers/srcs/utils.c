/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:08:46 by kadferna          #+#    #+#             */
/*   Updated: 2025/05/09 14:08:47 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	has_letters(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_numbers(char *c)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	len = ft_strlen(c);
	j = 0;
	while (i < len)
	{
		if (c[i] == ' ' || (c[i] >= 9 && c[i] <= 13))
			j = 0;
		if (c[i] >= '0' && c[i] <= '9')
			j = 0;
		j++;
		i++;
	}
	if (j >= 2)
		return (0);
	else
		return (1);
}

void	update_sign(const char *str, int *i, int *sign)
{
	if (str[(*i)] == '+' || str[(*i)] == '-')
	{
		if (str[(*i)] == '-')
			(*sign) = -1;
		(*i)++;
	}
}

int	is_valid_int(const char *str)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	sign = 1;
	num = 0;
    update_sign(str, &i, &sign);
	if (!str[i] || !ft_isdigit(str[i]))
		return (0);
	while (str[i] && ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1
				&& num > (long long)INT_MAX + 1))
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return ((int)num);
}
