/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:37:15 by kadferna          #+#    #+#             */
/*   Updated: 2024/12/11 14:37:18 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] != '\0')
	{
		while ((nptr[i] >= 9 && nptr[i] <= 31) || nptr[i] == ' ')
			i++;
		if (nptr[i] == '-')
		{
			sign = -1;
			i++;
		}
		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			return (0);
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			result = result * 10 + (nptr[i++] - '0');
		}
		break ;
	}
	return (result * sign);
}
/*
int	main(int ac, char **av)
{
	if (ac != 2)
	{
		return (1);
	}
	else
	{
		printf("%d \n", ft_atoi(av[1]));
		printf("%d \n", atoi(av[1]));
	}
	return 0;
}*/