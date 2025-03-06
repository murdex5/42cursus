/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:29:04 by kadferna          #+#    #+#             */
/*   Updated: 2025/02/28 18:29:06 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int		i;
	char	**map_arr;

	if (!map)
		return ;
	map_arr = map->content;
	i = 0;
	while (i < map->height)
	{
		if (map_arr && map_arr[i])
		{
			free(map_arr[i]);
			map_arr[i] = NULL;
		}
		i++;
	}
	if (map_arr)
		free(map_arr);
	map->content = NULL;
	free(map);
	map = NULL;
}

void	free_map_content(char **content, int height)
{
	int	i;

	if (!content)
		return ;
	i = 0;
	while (i < height)
	{
		if (content[i])
		{
			free(content[i]);
			content[i] = NULL;
		}
		i++;
	}
	free(content);
}

void	free_animation(t_animation *anime, t_vars *vars)
{
	if (anime)
	{
		free_animation(anime->next, vars);
		mlx_destroy_image(vars->mlx, anime->img);
		free(anime);
	}
}

void	free_player(t_player *p, t_vars *vars)
{
	if (p)
	{
		free_animation(p->idle, vars);
		free_animation(p->run, vars);
		free(p);
	}
}
void	free_vars(t_vars *vars)
{
	if (vars)
	{
		free_player(vars->player, vars);
		free_map(vars->map);
		free(vars);
	}
}
