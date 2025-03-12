/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:47:33 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/06 11:47:35 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars *vars;

	if (argc != 2)
		return (1);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->win, 600, 600, "HELLO");
	vars->map = parsing_map(argv[1]);
	if (!vars->map)
		return (1);
	vars->player = parse_player(vars, vars->map);
	if (!vars->player)
		return (1);
	mlx_loop_hook(vars->mlx, render_frame, vars);
	mlx_hook(vars->win, KeyPress, KeyPressMask, on_keypress, vars);
	mlx_loop(vars->mlx);
	return (0);
}
