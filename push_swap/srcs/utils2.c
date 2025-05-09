/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:59:50 by kadferna          #+#    #+#             */
/*   Updated: 2025/05/09 09:59:51 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**add_numbers(int argc, char **argv, int *len)
{
	char	**str_arr;
	int		i;

	i = 1;
	str_arr = malloc_and_set_null(argc);
	if (!str_arr)
		return (NULL);
	while (i < argc)
	{
		str_arr[i - 1] = ft_strdup(argv[i]);
		if (!str_arr[i - 1])
			return (free_str_list(str_arr), NULL);
		i++;
	}
	str_arr[argc - 1] = NULL;
	*len = argc - 1;
	return (str_arr);
}

static int	val_accumulator_func(long long *val_accumulator, int i,
		const char *num_str, int *sign)
{
	int	digit_count;

	digit_count = 0;
	while (num_str[i])
	{
		if (!ft_isdigit(num_str[i]))
			return (0);
		*val_accumulator = *val_accumulator * 10 + (num_str[i] - '0');
		digit_count++;
		if (*sign == 1 && *val_accumulator > INT_MAX)
			return (0);
		if (*sign == -1 && *val_accumulator > (long long)INT_MAX + 1)
			return (0);
		i++;
	}
	return (digit_count);
}

int	ft_parse_and_validate_long(const char *num_str, long long *out_val)
{
	long long	val_accumulator;
	int			i;
	int			sign;
	int			digit_count;

	if (!num_str || !*num_str)
		return (0);
	i = 0;
	sign = 1;
	if (num_str[i] == '+')
		i++;
	else if (num_str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (!num_str[i])
		return (0);
	val_accumulator = 0;
	digit_count = val_accumulator_func(&val_accumulator, i, num_str, &sign);
	if (digit_count == 0)
		return (0);
	*out_val = val_accumulator * sign;
	return (1);
}

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 32 && str[i + 1] == 32)
			return (0);
		i++;
	}
	return (1);
}
