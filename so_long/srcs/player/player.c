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
	player->idle = NULL;
	player->runing = NULL;
	return (player);
}

