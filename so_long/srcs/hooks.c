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
	if (vars->exit)
		free_texture(vars, vars->exit);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free_vars(vars);
}

void	check_bounderies(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->map->player_x;
	y = vars->map->player_y;
	if (vars->map->content[y][x] == '1')
	{
		while (vars->map->content[y][x] == '1')
		{
			if (vars->map->content[y - 1][x] != '1')
				y--;
			else if (vars->map->content[y][x - 1] != '1')
				x--;
			else if (vars->map->content[y - 1][x - 1] != '1')
			{
				y--;
				x--;
			}
			else
				break ;
			vars->map->player_x = x;
			vars->map->player_y = y;
		}
	}
}

void	player_move(int keysym, t_vars *vars)
{
	if (keysym == W)
	{
		vars->map->player_y -= 1;
		vars->player->player_state = 1;
	}
	if (keysym == A)
	{
		vars->map->player_x -= 1;
		vars->player->player_state = 1;
	}
	if (keysym == S)
	{
		vars->map->player_y += 1;
		vars->player->player_state = 1;
	}
	if (keysym == D)
	{
		vars->map->player_x += 1;
		vars->player->player_state = 1;
	}
}

int	on_keypress(int keysym, t_vars *vars)
{
	check_bounderies(vars);
	if (keysym == ESC)
	{
		on_key_press_exit(vars);
		exit(0);
	}
	if (keysym == W || keysym == A || keysym == S || keysym == D)
		player_move(keysym, vars);
	return (0);
}