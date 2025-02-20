/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:29:23 by kadferna          #+#    #+#             */
/*   Updated: 2025/02/17 10:02:19 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
    // void *mlx;
    // void *mlx_win;
    t_vars  vars;


    // t_data img;


 
    vars.mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello, world!");
    // img.img = mlx_new_image(mlx, 1000, 1000);
    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    // while (i < 50)
    // {
    //     j = 0;
    //     while (j < 50)
    //     {
    //         my_mlx_pixel_put(&img, 460+i, 500+j, 0x00FF0000);
    //         j++;
    //     }
    //     i++;
    // }    
    // i = 0;
    // while (i < 50)
    // {
    //     j = 0;
    //     while (j < 50)
    //     {
    //         my_mlx_pixel_put(&img, 460+i, 590+j, 0x00EB34E5);
    //         j++;
    //     }
    //     i++;
    // }
    vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello, World!");
    mlx_loop(vars.mlx);
}