/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:05:07 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/09 12:05:09 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (err_msg_std("./so_long <file>"), 1);
	map = parse_map(argv[1]);
	if (!map)
	{
		free_map(map);
		return (1);
	}
	free_map(map);
	return (0);
}
