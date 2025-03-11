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
	t_map *map;
	map = parsing_map("map.ber");
	if (!map)
	{
		ft_printf("Doesnt exist\n");
	}
	int i = 0;
	int j;
	while (i < map->height)
	{
		j = 0;
		while (map->content[i][j] != '\0')
		{
			ft_printf("%c", map->content[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}