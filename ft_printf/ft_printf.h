/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:27:52 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/23 12:27:54 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_print_addr(void *addr);
int		ft_abs(int c);
void	ft_putnbr_fd_unsigned(unsigned int n, int fd);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	check_char(va_list args);
void	check_str(va_list args);
void	check_mem(va_list args);
void	check_num(va_list args);
void	check_int(va_list args);
void	check_unsigned(va_list args);
void	to_decimal_lowercase(va_list args);
void	to_decimal_uppercase(va_list args);
void	print_basic(char c, va_list args);
void	print_number(char c, va_list args);
void	print_hexes(char c, va_list args);
int		ft_printf(const char *format, ...);

#endif