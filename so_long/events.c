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

void	run(t_vars *vars)
{
	vars->player->run = load_animation(vars, "./assets/player/player_run/",
			vars->player->h, vars->player->w);
	vars->player->idle = NULL;
}

void	idle(t_vars *vars)
{
	vars->player->idle = load_animation(vars, "./assets/player/player_idle/",
			vars->player->h, vars->player->w);
	vars->player->run = NULL;
}

int	move(int keysym, t_vars *vars)
{
	if (keysym == W)
		run(vars);
	if (keysym == A)
		run(vars);
	if (keysym == S)
		run(vars);
	if (keysym == D)
		run(vars);
	if (keysym == W || keysym == A || keysym == S || keysym == D)
		return (1);
	else
		return (0);
}

int	on_keypress(int keysym, t_vars *vars)
{
	if (keysym == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free_map(vars->map);
		free(vars);
	}
	if (!move(keysym, vars))
		idle(vars);
	mlx_loop_hook(vars->mlx, render_frame, &vars);
	return (0);
}
