/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:11:02 by kadferna          #+#    #+#             */
/*   Updated: 2025/05/14 14:11:03 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	has_letters(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}
int	check_each_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!has_letters(argv[i]))
			return (std_error("must not contain any letters"), 0);
		i++;
	}
	return (1);
}

int	checks(int argc, char **argv)
{
	if (argc != 6)
		return (std_error("There must be 5 args.\n./philo <num of philos> <time will die if does not eat> <eat time> <sleep time> <num of times to eat>\n"),
			0);
	if (!check_each_arg(argc, argv))
		return (0);
	return (1);
}
