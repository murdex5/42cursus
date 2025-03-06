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

int main()
{
    t_vars *vars;

	vars = NULL;
	vars = malloc(sizeof(t_vars));

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 800, 800, "HELLO");
    mlx_loop(vars->mlx);
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_display(vars->mlx);
    return (0);
}