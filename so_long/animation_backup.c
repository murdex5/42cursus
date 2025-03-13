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

void	render_animation(t_vars *vars, t_animation *anim)
{
	if (!vars || !anim || !anim->img)
		return ;
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, anim->img,
		vars->map->player_x, vars->map->player_y);
	anim = anim->next;
	usleep(105000);
}

int	diter_direction(t_vars *vars)
{
	if (vars->player->is_attacking == 0)
	{
		if (vars->player->player_direction == RIGHT)
		{
			if (vars->player->player_state == IDLE)
				render_player_frame(vars, vars->player->idle->right);
			else
				render_player_frame(vars, vars->player->run->right);
		}
		if (vars->player->player_direction == LEFT)
		{
			if (vars->player->player_state == IDLE)
				render_player_frame(vars, vars->player->idle->left);
			else
				render_player_frame(vars, vars->player->run->left);
		}
	}
	else
	{
		if (vars->player->player_direction == RIGHT)
			render_player_frame(vars, vars->player->attack->right);
		else
			render_player_frame(vars, vars->player->attack->left);
		vars->player->is_attacking = 0;
	}
	return (0);
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
