/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:29:49 by kadferna          #+#    #+#             */
/*   Updated: 2025/05/16 13:29:51 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_each_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!has_letters(argv[i]))
			return (std_error("must not contain any letters"), 0);
		if (!check_numbers(argv[i]))
			return (std_error("the number must be in range of int min to int max"),
				0);
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
