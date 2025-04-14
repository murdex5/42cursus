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

t_animation	*create_node(void *img)
{
	t_animation	*new_node;

	new_node = init_animation();
	if (!new_node)
		return (NULL);
	new_node->img = img;
	return (new_node);
}

void	add_node(t_animation **head, t_animation *new_node)
{
	t_animation	*current;

	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

int render_player(t_vars *vars)
{
	t_player *player;

	player = vars->player;
	if (!player->idle || !player->runing)
		return (0);
	if (player->player_state == 0)
		render_player_frame(vars, player->idle);
	else
		render_player_frame(vars, player->runing);
	return (0);
}

t_animation	*load_animation(t_vars *vars, char *path)
{
	int			i;
	void		*img;
	int			len;
	t_animation	*head;
	t_animation	*new_node;

	head = NULL;
	i = 0;
	while (i < 5)
	{
		len = 0;
		img = get_img(vars, path, len, i);
		if (!img)
			return (err_msg_std("Couldn't load animation"), NULL);
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
