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
#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				c;
	char			*str;
	int				num;
	void			*mem_loc;
	unsigned long	n;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				check_char(c, args);
			else if (*format == 's')
				check_str(str, args);
			else if (*format == 'p')
				check_mem(mem_loc, args);
			else if (*format == 'd')
				check_num(num, args);
			else if (*format == 'i')
				check_int(num, args);
			else if (*format == 'u')
				check_unsinged(n, args);
			else if (*format == 'x')
				to_decimal_lowercase(num, args);
			else if (*format == 'X')
				to_decimal_uppercase(num, args);
			else if (*format == '%')
				ft_putchar_fd('%', 1);
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