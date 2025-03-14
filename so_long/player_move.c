/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:50:04 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/14 07:50:17 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int keysym, t_vars *vars)
{
	t_player	*player;

	player = vars->player;
	if (keysym == D)
		player->pos_x += 4;
	if (keysym == A)
		player->pos_x -= 4;
	if (keysym == W)
		player->pos_y -= 4;
	if (keysym == S)
		player->pos_y += 4;
    return (0);
}
