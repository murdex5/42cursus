/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:02:19 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/14 10:02:21 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_texture	*init_txt(void)
{
	t_texture	*txt;

	txt = ft_calloc(sizeof(t_texture), 1);
	if (!txt)
		return (err_msg_std("Texture initializing failed"), NULL);
	txt->height = 16;
	txt->widht = 16;
	txt->img = NULL;
	return (txt);
}

void	*load_texture(t_vars *vars, char *path, int h, int w)
{
	void	*img;

	img = mlx_xpm_file_to_image(vars->mlx, path, &w, &h);
	if (!img)
		return (err_msg_std("Failed to load Textures"), NULL);
	return (img);
}

t_texture	*create_texture(t_vars *vars, char *path)
{
	t_texture	*texture;

	texture = init_txt();
	if (!texture)
		return (NULL);
	texture->img = load_texture(vars, path, texture->height, texture->widht);
	if (!texture->img)
		return (NULL);
	return (texture);
}

void	draw_texture(t_vars *vars, t_texture *texture, int x, int y)
{
	if (!vars || !texture || !texture->img)
		return ;
	mlx_put_image_to_window(vars->mlx, vars->win, texture->img, x, y);
}

void	draw_map(t_vars *vars)
{
	int	x;
	int	y;
	int	pixel_x;
	int	pixel_y;

	y = 0;
	while (y < vars->map->height)
	{
		x = 0;
		while (x < vars->map->width)
		{
			pixel_x = x * 16;
			pixel_y = y * 16;
			if (vars->map->content[y][x] == '1')
				draw_texture(vars, vars->water, pixel_x, pixel_y);
			else if (vars->map->content[y][x] == '0')
				draw_texture(vars, vars->floor, pixel_x, pixel_y);
			else if (vars->map->content[y][x] == 'C')
				draw_texture(vars, vars->collectibles, pixel_x, pixel_y);
			x++;
		}
		y++;
	}
}
