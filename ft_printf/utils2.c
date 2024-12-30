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

void check_char(int c, va_list args)
{
    c = va_arg(args, int);
    ft_putchar_fd(c, 1);
}

void check_str(char *str, va_list args)
{
    str =  va_arg(args, char *);
    ft_putstr_fd(str, 1);
}

void check_mem(void *p, va_list args)
{
    p = va_arg(args, void *);
    ft_print_addr(p);
}

void check_num(int num, va_list args)
{
    num = va_arg(args, int);
    ft_putnbr_fd(num, 1);
}

void check_int(int num, va_list args)
{
    num = va_arg(args, int);
    ft_putnbr_base(num, "0123456789");
}
