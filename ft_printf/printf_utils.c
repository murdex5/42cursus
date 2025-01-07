/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:05:46 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/07 12:05:48 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_chars(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c' || c == 's' || c == 'd')
		count = print_basic(c, args);
	else if (c == 'p')
		count = check_mem(args);
	else if (c == 'i' || c == 'u')
		count = print_number(c, args);
	else if (c == '%' || c == 'X' || c == 'x')
		count = print_hexes(c, args);
	else
	{
		ft_putchar_fd('?', 1);
		count = 1;
	}
	return (count);
}

int	count_first_param(const char *str)
{
	int	count;
	int	len;

	len = (int)ft_strlen((char *)str);
	count = 0;
	while (str[count] != '\0' && str[count + 1] != '\0')
	{
		if (str[count] == '%' && (str[count + 1] == 'c' || str[count + 1] == 's'
				|| str[count + 1] == 'd' || str[count + 1] == 'p' || str[count
				+ 1] == 'i' || str[count + 1] == 'u' || str[count + 1] == '%'
				|| str[count + 1] == 'x' || str[count + 1] == 'X'))
		{
			if (len != 0)
				len -= 2;
		}
		count++;
	}
	return (len);
}
