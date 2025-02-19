/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:16:37 by kadferna          #+#    #+#             */
/*   Updated: 2025/01/08 11:21:15 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_unsigned(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_fd_unsigned(n / 10, fd);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_putchar_fd((n + '0'), fd);
	}
}

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	int		base_len;
	char	c;
	int		i;

	i = -1;
	if (!base)
		return ;
	base_len = 0;
	while (base[base_len])
	{
		while (i < base_len)
		{
			if (base[i++] == base[base_len])
				return ;
		}
		if (base[base_len] == '+' || base[base_len] == '-')
			return ;
		base_len++;
	}
	if (base_len <= 1)
		return ;
	if (nbr >= (unsigned int)base_len)
		ft_putnbr_base(nbr / base_len, base);
	c = base[nbr % base_len];
	write(1, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	write(fd, str, i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_putchar_fd((n + '0'), fd);
	}
}
