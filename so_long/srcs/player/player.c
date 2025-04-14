/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:52:10 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/12 13:52:12 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = ft_calloc(sizeof(t_player), 1);
	if (!player)
		return (NULL);
	player->heigth = 16;
	player->width = 16;
	player->idle = NULL;
	player->runing = NULL;
	player->player_state = 0;
	return (player);
}

t_player	*player_pop(t_vars *vars)
{
	t_player	*player;

	player = init_player();
	if (!player)
		return (NULL);
	player->idle = load_animation(vars, "assets/player/player_idle/left/", player->heigth * 16, player->width * 16);
	player->runing = load_animation(vars, "assets/player/player_run/left/", player->heigth * 16, player->width * 16);
	if (!player->idle || !player->runing)
		return (free_player(vars, player), NULL);
	return (player);
}
