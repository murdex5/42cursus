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

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

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
void	check_char(int c, va_list args);
void	check_str(char *str, va_list args);
void	check_mem(void *p, va_list args);
void	check_num(int num, va_list args);
void	check_int(int num, va_list args);
int		ft_printf(const char *format, ...);

#endif