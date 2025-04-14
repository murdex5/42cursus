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

void	free_player(t_player *player)
{
	if (!player)
		return ;
	if (player->idle)
		free_animation(player->idle);
	if (player->heigth)
		free_animation(player->runing);
	free(player);
}