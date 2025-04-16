/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:56:03 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/10 14:56:04 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	on_key_press_exit(t_vars *vars)
{
	if (vars->player)
	{
		free_player(vars, vars->player);
		vars->player = NULL;
	}
	if (vars->floor)
		free_texture(vars, vars->floor);
	if (vars->water)
		free_texture(vars, vars->water);
	if (vars->collectibles)
		free_texture(vars, vars->collectibles);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free_vars(vars);
}

int	on_keypress(int keysym, t_vars *vars)
{
	if (keysym == ESC)
	{
		on_key_press_exit(vars);
		exit(0);
	}
	return (0);
}