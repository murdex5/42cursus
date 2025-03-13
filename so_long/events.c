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

static void	check_bounderies(t_vars *vars, int min, int max)
{
	t_map	*map;

	map = vars->map;
	if (vars->player->pos_x >= max)
		vars->player->pos_x = max - 1;
	if (vars->player->pos_x <= min)
		vars->player->pos_x = min + 1;
	if (vars->player->pos_y >= max)
		vars->player->pos_y = max - 1;
	if (vars->player->pos_y <= min)
		vars->player->pos_y = min + 1;
	if (map->content[vars->player->pos_y][vars->player->pos_x] == '1')
	{
		if (map->content[vars->player->pos_y - 1][vars->player->pos_x] != 1)
			vars->player->pos_y -= 1;
		if (map->content[vars->player->pos_y][vars->player->pos_x - 1] != 1)
			vars->player->pos_x -= 1;
	}
}
static void move(int keysym, t_vars *vars)
{
}

static void turn_player(int keysym, t_vars *vars)
{
	if (keysym == A)
		vars->player->player_direction = LEFT;
	if (keysym == D)
		vars->player->player_direction = RIGHT;
	if (keysym == W)
		vars->player->player_y_dir = UP;
	if (keysym == S)
		vars->player->player_y_dir = DOWN;
}
int	on_keypress(int keysym, t_vars *vars)
{
	check_bounderies(vars, 0, vars->map->width);
	if (keysym == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free_map(vars->map);
		free_player(vars->player);
		mlx_destroy_display(vars->mlx);
		exit(0);
	}
	if (keysym == W || keysym == D || keysym == A || keysym == S)
	{
		turn_player(keysym, vars);
		vars->player->player_state = RUN;
	}
	else
		vars->player->player_state = IDLE;
	return (0);
}
