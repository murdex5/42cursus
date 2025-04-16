/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:17:48 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/10 14:17:51 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_vars	*init_vars(void)
{
	t_vars	*vars;

	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		return (NULL);
	vars->mlx = NULL;
	vars->win = NULL;
	vars->map = NULL;
	vars->floor = NULL;
	vars->water = NULL;
	vars->player = NULL;
	return (vars);
}

int	init_mlx(t_vars *vars)
{
	if (!vars)
	{
		err_msg_std("Vars does no exist");
		return (0);
	}
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		ft_putstr_fd("So long: ", 1);
		ft_putstr_fd("Failed to initialize mlx\n", 1);
		return (0);
	}
	return (1);
}

int	make_window(t_vars *vars)
{
	if (!vars || !vars->mlx)
	{
		err_msg_std("Error");
		return (0);
	}
	vars->win = mlx_new_window(vars->mlx, vars->map->width * 64,
			vars->map->height * 64, "Knight game");
	if (!vars->win)
	{
		ft_putstr_fd("So long: ", 1);
		ft_putstr_fd("Failed to create the window\n", 1);
		mlx_destroy_display(vars->mlx);
		return (0);
	}
	return (1);
}

int	get_map(t_vars *vars, char *path)
{
	if (!vars || !vars->mlx)
	{
		err_msg_std("Error");
		return (0);
	}
	vars->map = parse_map(path);
	if (!vars->map)
	{
		free_map(vars->map);
		ft_putstr_fd("So long: ", 1);
		ft_putstr_fd("Failed to create the window\n", 1);
		return (0);
	}
	return (1);
}

int	get_textures(t_vars *vars)
{
	if (!vars || !vars->mlx || !vars->win)
	{
		err_msg_std("Error");
		return (0);
	}
	vars->floor = create_texture(vars, "assets/textures/floor/Path_Tile.xpm");
	vars->water = create_texture(vars, "assets/textures/water/Water_Tile.xpm");
	vars->collectibles = create_texture(vars, "assets/textures/collectibles/Collectible_Tile.xpm");
	vars->exit = create_texture(vars, "assets/textures/exit/Exit.xpm");
	if (vars->floor && vars->water && vars->collectibles && vars->exit)
		return (1);
	return (0);
}

int	get_player(t_vars *vars)
{
	if (!vars || !vars->mlx || !vars->win)
	{
		err_msg_std("Error");
		return (0);
	}
	vars->player = player_pop(vars);
	if (!vars->player)
		return (0);
	return (1);
}
