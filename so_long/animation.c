/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:36:09 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/12 09:36:31 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_animation	*create_node(void *img)
{
	t_animation	*new_node;

	new_node = malloc(sizeof(t_animation));
	if (!new_node)
		return (error_message("Failed to create a new node Mem err"), NULL);
	new_node->img = img;
	new_node->next = NULL;
	return (new_node);
}

static void	add_node(t_animation **head, t_animation *new_node)
{
	t_animation	*current;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

t_animation	*load_animation(t_vars *vars, char *path, int h, int w)
{
	int			i;
	void		*img;
	int			len;
	t_animation	*head;
	t_animation	*new_node;

	head = NULL;
	i = 0;
	while (i < ANIMATION_FRAMES)
	{
		len = 0;
		img = mlx_xpm_file_to_image(vars->mlx, ft_strjoin(path,
					ft_strjoin(int_to_str(len, i), ".xpm")), &w, &h);
		new_node = create_node(img);
		if (!new_node)
		{
			ft_printf("Failed to load the %s to the node.\n", ft_strjoin(path,
					ft_strjoin(int_to_str(len, i), ".xpm")));
			continue ;
		}
		add_node(&head, new_node);
		i++;
	}
	return (head);
}

static void	render_animation(t_vars *vars, t_animation *anim)
{
	if (!vars || !anim || !anim->img)
		return ;
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, anim->img,
		vars->map->player_x, vars->map->player_y);
	anim = anim->next;
}
int	render_player_animation(t_vars *vars)
{
	t_player *player;

	player = vars->player;
	if (player->player_direction == LEFT)
		render_animation(vars, player->run->left);
	if (player->player_direction == RIGHT)
		render_animation(vars, player->run->right);
	return (0);
}
