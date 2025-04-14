/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:49:50 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/14 10:49:52 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_player(t_vars *vars, t_player *player)
{
	if (!player)
		return ;
	if (player->idle)
	{
		free_animation(vars, player->idle);
		player->idle = NULL;
	}
	if (player->runing)
	{
		free_animation(vars, player->runing);
		player->runing = NULL;
	}
	free(player);
	player = NULL;
}
