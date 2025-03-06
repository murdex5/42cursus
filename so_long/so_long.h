/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:47:20 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/06 11:47:24 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Structs */

typedef struct s_animation
{
	void				*img;
	struct s_animation	*next;
}						t_animation;
typedef struct s_map
{
	char				**content;
	int					width;
	int					height;
	int					player_count;
	int					exit_count;
	int					collectables;
	int					player_x;
	int					player_y;
}						t_map;

typedef struct s_player
{
	t_animation			*idle;
	t_animation			*run;
	int					h;
	int					w;
}						t_player;
typedef struct s_vars
{
	void				*mlx;
	void				*win;
	// t_map	*map;
}						t_vars;

int						check_file_type(char *file, char *type);
int						check_path(t_map *map);
int						error_message(char *msg);
int						if_map_rectangled(t_map *map);
int						if_map_sorrounded(t_map *map);
int						check_map_contents(t_map *map);
int						check_map(t_map *map);
void					free_map(t_map *map);
void					free_map_content(char **content, int height);
void					clean_up(t_map *map);
t_map					*parsing_map(char *file);
#endif