/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/03/03 14:09:25 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/03 14:09:26 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	render_car(t_vars *vars)
{
	int x;
	int y;

	x = 350;
	y = 350;
	mlx_clear_window(vars->mlx, vars->win);
	while (x < 450)
	{
		while (y < 450)
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->player->run->img, vars->player->x, vars->player->y);
			y++;
		}
		y = 350;
		x++;
	}
	mlx_do_sync(vars->mlx);
	return (1);
}

int	main(void)
{
	t_vars *vars;

	vars = NULL;
	vars = malloc(sizeof(t_vars));

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 800, 800, "HELLO");

	vars->player = malloc(sizeof(t_player));
	vars->player->x = 0;
	vars->player->y = 0;
	vars->player->next = NULL;
	// load_animation_idle(vars, vars->player->run);
	mlx_loop_hook(vars->mlx, render_car, vars);
	mlx_hook(vars->win, KeyPress, KeyPressMask, on_keypress, vars);
	mlx_loop(vars->mlx);
}