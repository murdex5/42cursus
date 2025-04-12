/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:57:48 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/12 13:57:51 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_animation	*init_animation(void)
{
	t_animation	*anim;

	anim = ft_calloc(sizeof(t_animation), 1);
	if (!anim)
		return (NULL);
	anim->img = NULL;
	anim->next = NULL;
	return (anim);
}


t_animation *load_animation(char *path)
{
    
}