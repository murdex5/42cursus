/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:51:04 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/10 14:51:05 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_vars(t_vars *vars)
{
	if (!vars)
		return ;
	if (vars->map)
		free_map(vars->map);
	free(vars);
}
