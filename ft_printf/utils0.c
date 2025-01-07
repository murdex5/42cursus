/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:14:33 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/30 13:14:35 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

void	ft_print_addr(void *p0)
{
	int			i;
	int			leading_zero;
	uintptr_t	p;
	int			hex_val;

	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	p = (uintptr_t)p0;
	i = sizeof(p) * 8 - 4;
	leading_zero = 1;
	while (i >= 0)
	{
		hex_val = (p >> i) & 0xf;
		if (hex_val != 0 || !leading_zero)
		{
			ft_putchar_fd(hex_digit(hex_val), 1);
			leading_zero = 0;
		}
		i -= 4;
	}
	if (leading_zero)
	{
		ft_putchar_fd('0', 1);
	}
}

void	check_unsigned(va_list args)
{
	unsigned long long n;

	n = va_arg(args, unsigned long);
	ft_putnbr_fd_unsigned(n, 1);
}