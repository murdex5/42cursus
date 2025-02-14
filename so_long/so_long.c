/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:29:23 by kadferna          #+#    #+#             */
/*   Updated: 2025/02/14 10:29:26 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int main(void)
{
    void    *mlx;
    void    *mlx_win;

    mlx =  mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");
    mlx_loop(mlx);
}