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

/* Variables */

# define ANIMATION_FRAMES 6

/* DATA TYPES */

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

# define RUN 1
# define IDLE 0
# define RIGHT 3
# define LEFT 4
# define UP 5
# define DOWN 6

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

typedef struct s_pdirec
{
	t_animation			*left;
	t_animation			*right;
}						t_pdirec;

typedef struct s_player
{
	t_pdirec			*idle;
	t_pdirec			*run;
	t_pdirec			*attack;
	int					h;
	int					w;
	int					pos_x;
	int					pos_y;
	int					player_state;
	int					player_y_dir;
	int					player_direction;
	int					is_attacking;
}						t_player;
typedef struct s_vars
{
	void				*mlx;
	void				*win;
	t_map				*map;
	t_player			*player;
}						t_vars;

int						on_keypress(int keysym, t_vars *vars);
int						set_player_to_idle(int keysym, t_vars *vars);
int						on_mouse_click(int button, int x, int y, t_vars *vars);
char					*int_to_str(int len, int num);
int						count_lines(char *file);
int						check_file_type(char *file, char *type);
int						error_message(char *msg);
int						alloc_mem(t_map *map, int line_count);
char					**copy_map(t_map *map);
int						flood_filling(t_map *map, char **map_copy, int x,
							int y);
int						flood_fill(char **map, int x, int y, int *collectibles);
int						read_map_file(t_map *map, char *file);
int						store_player_position(t_map *map);
void					free_anim(t_animation **head);
void					free_player(t_player *player);
void					free_map(t_map *map);
void					free_map_content(char **content, int height);
int						free_str(char **content, int i);
void					free_vars(t_vars *vars);
int						check_map(t_map *map);
t_map					*parsing_map(char *file);
t_animation				*load_animation(t_vars *vars, char *path, int h, int w);
t_pdirec				*load_dir_animation(t_vars *vars, char *path, int h,
							int w);
t_player				*parse_player(t_vars *vars, t_map *map);
int						render_player_animation(t_vars *vars);
/*int						render_player_frame(t_vars *vars,
							t_animation *anim);
int	diter_direction(t_vars *vars); */
#endif