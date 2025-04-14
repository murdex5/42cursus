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

void	*get_img(t_vars *vars, char *path, int len, int i)
{
	char	*str1;
	char	*str2;
	char	*str3;
	void	*img;

	str3 = int_to_str(len, i);
	str2 = ft_strjoin(str3, ".xpm");
	str1 = ft_strjoin(path, str2);
	img = mlx_xpm_file_to_image(vars->mlx, str1, &vars->player->width,
			&vars->player->heigth);
	free(str1);
	free(str2);
	free(str3);
	return (img);
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
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, anim->img,
		vars->map->player_x, vars->map->player_y);
	anim = anim->next;
}
