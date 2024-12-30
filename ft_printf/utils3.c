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
#include "libftprintf.h"

void	check_unsigned(va_list args)
{
	unsigned long long	n;

	n = va_arg(args, unsigned long);
	ft_putnbr_fd_unsigned(n, 1);
}

void	to_decimal_lowercase(va_list args)
{
	int	num;

	num = va_arg(args, int);
	ft_putnbr_base(num, "0123456789abcdef");
}

void	to_decimal_uppercase(va_list args)
{
	int	num;

	num = va_arg(args, int);
	ft_putnbr_base(num, "0123456789ABCDEF");
}

void	print_basic(char c, va_list args)
{
	if (c == 'c')
		check_char(args);
	if (c == 's')
		check_str(args);
	if (c == 'd')
		check_num(args);
}
void	print_hexes(char c, va_list args)
{
	if (c == 'x')
		to_decimal_lowercase(args);
	if (c == 'X')
		to_decimal_uppercase(args);
	if (c == '%')
		ft_putchar_fd('%', 1);
}