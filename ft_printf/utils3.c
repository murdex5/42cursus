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

void	check_unsinged(unsigned long n, va_list args)
{
	n = va_arg(args, unsigned long);
	ft_putnbr_fd_unsigned(n, 1);
}

void to_decimal_lowercase(int num, va_list args)
{
    num = va_arg(args, int);
    ft_putnbr_base(num, "0123456789abcdef");
}

void to_decimal_uppercase(int num, va_list args)
{
    num = va_arg(args, int);
    ft_putnbr_base(num, "0123456789ABCDEF");
}