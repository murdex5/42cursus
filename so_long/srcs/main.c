/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:05:07 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/09 12:05:09 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	var_pop(t_vars **vars, char *path)
{
	*vars = init_vars();
	if (!vars)
		return (0);
	if (!init_mlx(*vars))
		return (0);
	if (!get_map(*vars, path))
		return (0);
	if (!make_window(*vars))
		return (0);
	if (!get_textures(*vars))
		return (0);
	if (!get_player(*vars))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		return (err_msg_std("./so_long <file>"), 1);
	vars = NULL;
	if (!var_pop(&vars, argv[1]))
	{
		free_vars(vars);
		return (1);
	}
	draw_map(vars);
	mlx_hook(vars->win, KeyPress, KeyPressMask, on_keypress, vars);
	mlx_loop(vars->mlx);
	return (0);
}
