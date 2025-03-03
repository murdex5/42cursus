/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:53:17 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/03 10:53:19 by kadferna         ###   ########.fr       */
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
//         return 1;
//     }

//     data.mlx_ptr = mlx_init();
//     if (!data.mlx_ptr) {
//         fprintf(stderr, "Error: mlx_init failed\n");
//         free_map(map);
//         return 1;
//     }

//     data.win_ptr = mlx_new_window(data.mlx_ptr, 288, 240, "hi :)");
//     if (!data.win_ptr) {
//         fprintf(stderr, "Error: mlx_new_window failed\n");
//         mlx_destroy_display(data.mlx_ptr);
//         free_map(map);
//         return 1;
//     }

//     data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/House.xpm", &img_width, &img_height);
//     if (!data.img_ptr) {
//         fprintf(stderr, "Error: mlx_xpm_file_to_image failed\n");
//         mlx_destroy_window(data.mlx_ptr, data.win_ptr);
//         mlx_destroy_display(data.mlx_ptr);
//         free_map(map);
//         return 1;
//     }

//     mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0); // Draw at (0, 0)

//     mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
//     mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

//     mlx_loop(data.mlx_ptr);

//     mlx_destroy_image(data.mlx_ptr, data.img_ptr);
//     mlx_destroy_window(data.mlx_ptr, data.win_ptr);
//     mlx_destroy_display(data.mlx_ptr);
//     free_map(map);

//     return (0);
// }


void render_square(t_data *mlx, t_data *win, int color)
{
    int x;
    int y;

    x = 350;
    y = 350;

    while (x < 450)
    {
        while (y < 450)
        {
            mlx_pixel_put(mlx, win, x, y, color);
            y++;
        }
        y = 350;
        x++;
    }
}
int quit(int keycode, t_vars *vars)
{
    if (keycode == ESC)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        free(vars);
        exit(0);
    }
    return (0);
}

int main(void)
{
    t_vars *vars;

    vars = NULL;
    vars = malloc(sizeof(t_vars));

    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, 600, 600, "Test");

    mlx_hook(vars->win, 2, 0, quit, vars);
    mlx_loop(vars->mlx);
    return 0;
}