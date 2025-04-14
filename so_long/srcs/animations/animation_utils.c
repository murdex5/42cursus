/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:45:59 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/14 12:46:02 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*get_img(char *path, int len, int i)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str3 = int_to_str(len, i);
	str2 = ft_strjoin(path, str3);
	str1 = ft_strjoin(str2, ".xpm");
	free(str2);
	free(str3);
	if (access(str1, F_OK) == 0)
		return (str1);
	return (NULL);
}

int	render_player_frame(t_vars *vars, t_animation *anim)
{
	static t_animation	*current_frame = NULL;

	if (!current_frame)
		current_frame = anim;
	render_animation(vars, current_frame);
	current_frame = current_frame->next;
	if (!current_frame)
		current_frame = anim;
	return (0);
}

void	render_animation(t_vars *vars, t_animation *anim)
{
	if (!vars || !anim || !anim->img)
		return ;
	if (vars->map->player_x < 0 || vars->map->player_y < 0)
		return ;
	mlx_put_image_to_window(vars->mlx, vars->win, anim->img,
		vars->map->player_x, vars->map->player_y);
}
