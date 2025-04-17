/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:42:57 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/17 14:42:59 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exited(t_vars *vars, int new_x, int new_y)
{
	if (vars->map->content[new_y][new_x] == 'E')
	{
		if (vars->map->collectibles == 0)
		{
			on_key_press_exit(vars);
			exit(0);
		}
		else
			ft_printf("Collect all the coins to Exit :)\n");
	}
}
