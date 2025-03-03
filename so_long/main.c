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


// int main(int argc, char **argv) {
//     t_data data;
//     t_map *map;
//     int img_width, img_height;

//     if (argc != 2)
//         return (1);

//     map = parsing_map(argv[1]);
//     if (!map) {
//         fprintf(stderr, "Error: parsing_map failed\n");
//         return (1);
//     }

//     data.mlx_ptr = mlx_init();
//     if (!data.mlx_ptr) {
//         fprintf(stderr, "Error: mlx_init failed\n");
//         free_map(map);
//         return (1);
//     }

//     data.win_ptr = mlx_new_window(data.mlx_ptr, 288, 240, "hi :)");
//     if (!data.win_ptr) {
//         fprintf(stderr, "Error: mlx_new_window failed\n");
//         mlx_destroy_display(data.mlx_ptr);
//         free_map(map);
//         return (1);
//     }

//     data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/House.xpm",
// 		&img_width, &img_height);
//     if (!data.img_ptr) {
//         fprintf(stderr, "Error: mlx_xpm_file_to_image failed\n");
//         mlx_destroy_window(data.mlx_ptr, data.win_ptr);
//         mlx_destroy_display(data.mlx_ptr);
//         free_map(map);
//         return (1);
//     }

//     mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
// 	Draw at (0, 0)

//     mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
//     mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
// 	&data);

//     mlx_loop(data.mlx_ptr);

//     mlx_destroy_image(data.mlx_ptr, data.img_ptr);
//     mlx_destroy_window(data.mlx_ptr, data.win_ptr);
//     mlx_destroy_display(data.mlx_ptr);
//     free_map(map);

//     return (0);
// }

int	keys(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars);
		exit(0);
	}
	if (keycode == W)
		vars->box_y -= 10;
	if (keycode == A)
		vars->box_x -= 10;
	if (keycode == S)
		vars->box_y += 10;
	if (keycode == D)
		vars->box_x += 10;
	ft_printf("%d\n", keycode);
	return (0);
}

int	close_program(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars);
	exit(0);
	return (0);
}

/* Function to render the square */
int	render_square(t_vars *vars)
{
	int x;
	int y;

	mlx_clear_window(vars->mlx, vars->win);
	/* Draw the square at the current position */
	x = 0;
	while (x < 100)
	{
		y = 0;
		while (y < 100)
		{
			mlx_pixel_put(vars->mlx, vars->win, x + vars->box_x + 350, y
				+ vars->box_y + 350, 0xFFDDFF);
			y++;
		}
		x++;
	}
	return (1);
}

int	main(void)
{
	t_vars *vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);

	vars->box_x = 0;
	vars->box_y = 0;
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		free(vars);
		return (1);
	}
	vars->win = mlx_new_window(vars->mlx, 600, 600, "Test");
	if (!vars->win || !vars->mlx)
	{
		free(vars);
		return (1);
	}
	mlx_loop_hook(vars->mlx, render_square, vars);
	mlx_hook(vars->win, KeyRelease, KeyReleaseMask, &on_keypress, vars);
	mlx_hook(vars->win, 17, 0, close_program, vars);
	mlx_loop(vars->mlx);
	return (0);
}
