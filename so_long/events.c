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

// void	run(t_vars *vars)
// {
// 	vars->player->run = load_animation(vars, "./assets/player/player_run/",
// 			vars->player->h, vars->player->w);
// 	vars->player->idle = NULL;
// }

// void	idle(t_vars *vars)
// {
// 	vars->player->idle = load_animation(vars, "./assets/player/player_idle/",
// 			vars->player->h, vars->player->w);
// 	vars->player->run = NULL;
// }

int	move(int keysym, t_vars *vars)
{
	if (keysym == W || keysym == A || keysym == S || keysym == D)
	{
		if (keysym == W)
		vars->map->player_y -= 5;
		if (keysym == S)
			vars->map->player_y += 5;
		if (keysym == A)
		{
			vars->player->player_direction = LEFT;
			vars->map->player_x -= 5;
		}
		if (keysym == D)
		{
			vars->player->player_direction = RIGHT;
			vars->map->player_x  += 5;
		}
		return (1);
	}
	else
		return (0);
}

int	on_keypress(int keysym, t_vars *vars)
{
	if (keysym == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
	}
	if (!move(keysym, vars))
		vars->player->player_state = IDLE;
	else
		vars->player->player_state = RUN;
	return (0);
}
