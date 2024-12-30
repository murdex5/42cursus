/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:34:06 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/30 13:34:08 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_char(va_list args)
{
	int	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
}

void	check_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	ft_putstr_fd(str, 1);
}

void	check_mem(va_list args)
{
	void	*p;

	p = va_arg(args, void *);
	ft_print_addr(p);
}

void	check_num(va_list args)
{
	int	num;

	num = va_arg(args, int);
	ft_putnbr_fd(num, 1);
}

void	check_int(va_list args)
{
	int	num;

	num = va_arg(args, int);
	ft_putnbr_base(num, "0123456789");
}
