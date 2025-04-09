/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 06:56:01 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/13 07:05:32 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_pdirec	*init_ani_dir(void)
{
	t_pdirec	*player_direction;

	player_direction = malloc(sizeof(t_pdirec));
	if (!player_direction)
		return (NULL);
	player_direction->left = NULL;
	player_direction->right = NULL;
	return (player_direction);
}

t_pdirec	*load_dir_animation(t_vars *vars, char *path, int h, int w)
{
	t_pdirec *player_direction;

	player_direction = init_ani_dir();
	if (!player_direction)
		return (error_message("failed to Initialize the animations"), NULL);
	player_direction->left = load_animation(vars, ft_strjoin(path, "left/"), h,
			w);
	player_direction->right = load_animation(vars, ft_strjoin(path, "right/"),
			h, w);
	if (!player_direction->left || !player_direction->right)
		return (error_message("failed to load the animations"), NULL);
	return (player_direction);
}
