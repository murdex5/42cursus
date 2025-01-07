/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:51:39 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/30 13:51:40 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	to_decimal_lowercase(va_list args)
{
	int	num;
	int	count;

	num = va_arg(args, int);
	count = count_hex_digits(num);
	ft_putnbr_base(num, "0123456789abcdef");
	return (count);
}

int	to_decimal_uppercase(va_list args)
{
	int	num;
	int	count;

	num = va_arg(args, int);
	count = count_hex_digits(num);
	ft_putnbr_base(num, "0123456789ABCDEF");
	return (count);
}

int	print_basic(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = check_char(args);
	if (c == 's')
		count = check_str(args);
	if (c == 'd')
		count = check_num(args);
	return (count);
}
int	print_hexes(char c, va_list args)
{
	int	count;

	if (c == 'x')
		count = to_decimal_lowercase(args);
	if (c == 'X')
		count = to_decimal_uppercase(args);
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (count);
}

int	print_number(char c, va_list args)
{
	int	count;

	if (c == 'i')
		count = check_int(args);
	if (c == 'u')
		count = check_unsigned(args);
	return (count);
}
