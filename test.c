
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// #include "ft_printf.h"


void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// static char	hex_digit(int v)
// {
// 	if (v >= 0 && v < 10)
// 		return ('0' + v);
// 	else
// 		return ('a' + v - 10);
// }

// int	ft_print_addr(void *p0)
// {
// 	int			i;
// 	int			leading_zero;
// 	uintptr_t	p;
// 	int			hex_val;
// 	int count = 2;

// 	ft_putchar_fd('0', 1);
// 	ft_putchar_fd('x', 1);
// 	p = (uintptr_t)p0;
// 	i = sizeof(p) * 8 - 4;
// 	leading_zero = 1;
// 	while (i >= 0)
// 	{
// 		hex_val = (p >> i) & 0xf;
// 		if (hex_val != 0 || !leading_zero)
// 		{
// 			ft_putchar_fd(hex_digit(hex_val), 1);
// 			count++;
// 			leading_zero = 0;
// 		}
// 		i -= 4;
// 	}
// 	if (leading_zero)
// 	{
// 		ft_putchar_fd('0', 1);
// 		count++;
// 	}
// 	return (count);
// }


static char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

static void	check_val(int hex_val, int *leading_zero, int *count)
{
	if (hex_val != 0 || !(*leading_zero))
	{
		ft_putchar_fd(hex_digit(hex_val), 1);
		(*count)++;
		(*leading_zero) = 0;
	}
}

int	ft_print_addr(void *p0)
{
	int			i;
	int			leading_zero;
	uintptr_t	p;
	int			hex_val;
	int			count;

	count = 2;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	p = (uintptr_t)p0;
	i = sizeof(p) * 8 - 4;
	leading_zero = 1;
	while (i >= 0)
	{
		hex_val = (p >> i) & 0xf;
		check_val(hex_val, &leading_zero, &count);
		i -= 4;
	}
	if (leading_zero)
	{
		ft_putchar_fd('0', 1);
		count++;
	}
	return (count);
}

int	main(void)
{
	char *str = "Hello, Worfgfdgdfgdfgdfgld";
	int count = ft_print_addr(&str);
	printf("\n");
	printf("%d\n", count);
	return (0);
}