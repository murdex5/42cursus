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
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '+'
				|| str[i] == '-'))
			i++;
		else
			return (0);
	}
	return (1);
}

int	str_len(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

static int	is_valid_number(const char *str)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && (-num) < INT_MIN))
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	check_numbers(int *nums, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (std_error("Must be in range of INT_MIN and INT_MAX"), 0);
		nums[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (argc == 5)
		nums[5] = 0;
	return (1);
}
