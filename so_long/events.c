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

void	check_bounderies(t_vars *vars, int min, int max)
{
	if (vars->map->player_x >= max)
		vars->map->player_x = max - 1;
	if (vars->map->player_x <= min)
		vars->map->player_x = min + 1;
	if (vars->map->player_y >= max)
		vars->map->player_y = max - 1;
	if (vars->map->player_y <= min)
		vars->map->player_y = min + 1;
}

int	move(int keysym, t_vars *vars)
{
	check_bounderies(vars, 0, 200);
	if (keysym == W || keysym == A || keysym == S || keysym == D)
	{
		if (keysym == W)
			vars->map->player_y -= 4;
		if (keysym == S)
			vars->map->player_y += 4;
		if (keysym == A)
		{
			vars->player->player_direction = LEFT;
			vars->map->player_x -= 4;
		}
		if (keysym == D)
		{
			vars->player->player_direction = RIGHT;
			vars->map->player_x += 4;
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
		free_map(vars->map);
		free_player(vars->player);
		mlx_destroy_display(vars->mlx);
		exit(0);
	}
	if (move(keysym, vars))
		vars->player->player_state = RUN;
	return (0);
}

int	set_player_to_idle(int keysym, t_vars *vars)
{
	vars->player->player_state = IDLE;
	vars->player->is_attacking = 0;
	return (keysym * 0);
}

int	on_mouse_click(int button, int x, int y, t_vars *vars)
{
	int	i;

	i = 0;
	if (button == 1)
		vars->player->is_attacking = 1;
	return (x + y + i * 0);
}
