/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:05:57 by kadferna          #+#    #+#             */
/*   Updated: 2025/02/26 10:05:59 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// int	on_keypress(int keysym, t_data *data)
// {
// 	(void)data;
// 	ft_printf("Pressed key: %d\n", keysym);
// 	return (0);
// }

int on_keypress(int keysym, t_vars *vars)
{
	(void)vars;
	if (keysym == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars);
		exit(0);
	}
	if (keysym == W)
		vars->player->y -= 10;
	if (keysym == A)
		vars->player->x -= 10;
	if (keysym == S)
		vars->player->y += 10;
	if (keysym == D)
		vars->player->x  += 10;
	//ft_printf("%d\n", keysym);
	return (0);
}

int	on_destroy(t_vars *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

