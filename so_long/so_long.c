/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/02/14 10:29:23 by kadferna          #+#    #+#             */
/*   Updated: 2025/02/17 10:02:19 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int argc, char **argv)
{
	char *map;

	if (argc != 2)
		return (0);
	map = argv[1];
	ft_printf("The file: %d\n", check_map(map));
	int i = parsing_map(map);
	ft_printf("The num %d\n", i);
	return (0);
}
