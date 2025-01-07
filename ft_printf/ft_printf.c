/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:30:28 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/30 08:42:48 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int count;

	count = count_first_param(format);
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += check_chars(*format, args);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	ft_printf("%i %i", 2147483647, (int)-2147483648);
	return (0);
}*/