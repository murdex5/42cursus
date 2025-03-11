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
	t_vars	*vars;

	if (argc != 2)
		return (0);
	vars = NULL;
	vars = malloc(sizeof(t_vars));
	vars->mlx = mlx_init();
	vars->map = parsing_map(argv[1]);
	if (!vars->map)
	{
		return (1);
	}
	vars->win = mlx_new_window(vars->mlx, 800, 800, "HELLO");
	mlx_loop(vars->mlx);
	mlx_hook(vars->mlx, KeyRelease, KeyPressMask, on_keypress, vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	return (0);
}
