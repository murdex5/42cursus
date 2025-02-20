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

	t_map_dims	k = parsing_map(map);
	ft_printf("length: %d width: %d\n", k.height, k.width);
	return (0);
}
