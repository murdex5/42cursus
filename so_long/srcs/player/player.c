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
	player->heigth = 192;
	player->width = 192;
	if (!player)
		return (NULL);
	player->idle = NULL;
	player->runing = NULL;
	return (player);
}

t_player	*player_pop(t_vars *vars)
{
	t_player *player;

	player = init_player();
	if (!player)
		return (NULL);
	player->idle = load_animation(vars, "../../assets/player/player_idle/",
			player->heigth, player->width);
	player->idle = load_animation(vars, "../../assets/player/player_run/",
			player->heigth, player->width);
	return (player);
}
