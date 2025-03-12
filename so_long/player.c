/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:48:09 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/06 11:48:14 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (error_message("Failed to create the player"), NULL);
	player->h = 192;
	player->w = 192;
	player->pos_x = 0;
	player->pos_y = 0;
	player->idle = NULL;
	player->run = NULL;
	return (player);
}

t_player	*parse_player(t_vars *vars, t_map *map)
{
	t_player	*player;

	if (!vars || !map)
		return (error_message("one of the parameteres are NULL"), NULL);
	player = init_player();
	if (!player)
		return (NULL);
	player->pos_x = map->player_x;
	player->pos_y = map->player_y;
	player->idle = load_animation(vars, "/assets/player/player_idle/");
    if (!player->idle)
    {
        free(player);
        return (NULL);
    }
	player->run = load_animation(vars, "/assets/player/player_idle/");
    if (!player->run)
    {
        free(player);
        return (NULL);
    }
	return (player);
}
