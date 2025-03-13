/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:51:43 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/06 11:51:46 by kadferna         ###   ########.fr       */
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
		free(content[i]);
		i++;
	}
	free(content);
}

void	free_anim(t_animation **head)
{
	t_animation	*current;
	t_animation	*next;

	if (*head == NULL)
		return ;
	current = *head;
	while (current != NULL)
	{
		next = current->next;
		if (current->img != NULL)
		{
			free(current->img);
			current->img = NULL;
		}
		free(current);
		current = next;
	}
	*head = NULL;
}

void	free_pdirec(t_pdirec *direction)
{
	if (!direction)
		return ;
	if (direction->left)
		free_anim(&direction->left);
	if (direction->right)
		free_anim(&direction->right);
	free(direction);
	direction = NULL;
}

void	free_player(t_player *player)
{
	if (!player)
		return ;
	if (player->idle)
		free_pdirec(player->idle);
	if (player->run)
		free_pdirec(player->run);
	free(player);
}

void	free_vars(t_vars *vars)
{
	if (!vars)
		return ;
	/*
	if (vars->mlx)
		free(vars->mlx);
	if (vars->win)
		free(vars->win);*/
	if (vars->map)
		free_map(vars->map);
	if (vars->win)
		free_player(vars->player);
	free(vars);
}
