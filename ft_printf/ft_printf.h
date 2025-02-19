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

int		ft_print_addr(void *p0);
int		ft_abs(int c);
void	ft_putnbr_fd_unsigned(unsigned int n, int fd);
void	ft_putnbr_base(unsigned int nbr, char *base);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(char *str);
int		check_char(va_list args);
int		check_str(va_list args);
int		check_mem(va_list args);
int		check_num(va_list args);
int		check_int(va_list args);
int		check_unsigned(va_list args);
int		to_decimal_lowercase(va_list args);
int		to_decimal_uppercase(va_list args);
int		print_basic(char c, va_list args);
int		print_number(char c, va_list args);
int		print_hexes(char c, va_list args);
int		count_digits(int nb);
int		count_unsigned_digits(unsigned int nb);
int		count_hex_digits(unsigned int nb);
int		check_chars(char c, va_list args);
int		count_first_param(const char *str);
int		ft_printf(const char *format, ...);

#endif