/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:06:54 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/22 12:06:56 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_enemy	*init_enemy(void)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy)
		return (NULL);
	enemy->left = NULL;
	enemy->right = NULL;
	return (enemy);
}

t_enemy	*pop_enemy(t_vars *vars)
{
	t_enemy	*enemy;

	enemy = init_enemy();
	if (!enemy)
		return (NULL);
	enemy->left = load_animation(vars, "assets/enemy/left/", 64, 64);
	enemy->right = load_animation(vars, "assets/enemy/right/", 64, 64);
	enemy->player_dir = 0;
	if (!enemy->left || !enemy->right)
	{
		free_enemy(vars, enemy);
		return (NULL);
	}
	return (enemy);
}
int	render_enemy_frame(t_vars *vars, t_animation *anim)
{
	static t_animation	*current_frame = NULL;
	static int			frame_counter = 0;
	int					frame_delay;

	frame_delay = 1000;
	if (!current_frame)
		current_frame = anim;
	render_enemy(vars, current_frame);
	frame_counter++;
	if (frame_counter >= frame_delay)
	{
		frame_counter = 0;
		current_frame = current_frame->next;
		if (!current_frame)
			current_frame = anim;
	}
	return (0);
}

void	render_enemy(t_vars *vars, t_animation *anim)
{
	int	pixel_x;
	int	pixel_y;

	if (!vars || !anim || !anim->img)
		return ;
	if (vars->map->enemy_x < 0 || vars->map->enemy_y < 0)
		return ;
	pixel_x = vars->map->enemy_x * 64;
	pixel_y = vars->map->enemy_y * 64;
	mlx_put_image_to_window(vars->mlx, vars->win, anim->img, pixel_x, pixel_y);
}

void	enemy_move(t_vars *vars)
{
	int	move_range_tiles;
	int	target_y;
	int	current_y;

	move_range_tiles = 5;
	if (vars->frames != 800)
		return ;
	target_y = vars->static_enem_loc + move_range_tiles;
	if (target_y >= vars->map->height)
		target_y = vars->map->height - 2;
	current_y = vars->map->enemy_y;
	if (vars->have_visited == 1)
	{
		if (current_y > vars->static_enem_loc)
			vars->map->enemy_y -= 1;
		else if (current_y == vars->static_enem_loc)
			vars->have_visited = 0;
	}
	else
	{
		if (current_y < target_y)
			vars->map->enemy_y += 1;
		else if (current_y == target_y)
			vars->have_visited = 1;
	}
}
