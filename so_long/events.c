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
		vars->car->y -= 10;
	if (keysym == A)
		vars->car->x -= 10;
	if (keysym == S)
		vars->car->y += 10;
	if (keysym == D)
		vars->car->x  += 10;
	//ft_printf("%d\n", keysym);
	return (0);
}

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

