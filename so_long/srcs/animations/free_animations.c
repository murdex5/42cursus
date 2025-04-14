/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:47:11 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/14 10:47:12 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_animation(t_animation *animation)
{
	if (!animation)
		return ;

	while (animation->img)
	{
		free(animation->img);
		animation->img = animation->next;
	}
	free(animation);
}