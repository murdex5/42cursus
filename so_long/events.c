/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:32:14 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/08 12:32:27 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keypress(int keysym, t_vars *vars)
{
	if (keysym == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free_map(vars->map);
		free(vars);
	}
	if (keysym == W)
	{
		ft_printf("W\n");
	}
	if (keysym == A)
		ft_printf("A\n");
	if (keysym == S)
		ft_printf("S\n");
	if (keysym == D)
		ft_printf("D\n");
	return (0);
}
