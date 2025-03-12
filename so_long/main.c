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

int main(int argc, char **argv)
{
    t_vars vars;
    // Check for correct number of arguments
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
        return 1;
    }

    // Initialize MLX
    vars.mlx = mlx_init();
    if (!vars.mlx)
    {
        fprintf(stderr, "Error: Failed to initialize MLX\n");
        return 1;
    }

    // Create a window
    vars.win = mlx_new_window(vars.mlx, 600, 600, "HELLO");
    if (!vars.win)
    {
        fprintf(stderr, "Error: Failed to create window\n");
        mlx_destroy_display(vars.mlx);
        return 1;
    }

    // Parse the map
    vars.map = parsing_map(argv[1]);
    if (!vars.map)
    {
        fprintf(stderr, "Error: Failed to parse map\n");
        mlx_destroy_window(vars.mlx, vars.win);
        mlx_destroy_display(vars.mlx);
        return 1;
    }

    vars.player = parse_player(&vars, vars.map);

	mlx_hook(vars.mlx, KeyPress, KeyPressMask, on_keypress, &vars);
    mlx_loop(vars.mlx);

    return 0;
}