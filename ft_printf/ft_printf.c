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

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c' || *format == 's' || *format == 'd')
				print_basic(*format, args);
			else if (*format == 'p')
				check_mem(args);
			else if (*format == 'i' || *format == 'u')
				print_number(*format, args);
			else if (*format == '%' || *format == 'X' || *format == 'x')
				print_hexes(*format, args);
			else
				ft_putchar_fd('?', 1);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (0);
}

// int	main(void)
// {
// 	ft_printf("Hello, my name is %s, I am %u years old \n", "Malsha", -934);
// 	printf("Hello, my name is %s, I am %u years old\n", "Malsha", -934);
// 	return (0);
// }