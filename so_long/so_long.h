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

# define IDLE 0
# define RUN 1
# define ATTACK 2
# define RIGHT 3
# define LEFT 4

/* Structs */

typedef struct s_texture
{
	void				*img;
	int					height;
	int					widht;
}						t_texture;

typedef struct s_animation
{
	void				*img;
	struct s_animation	*next;
}						t_animation;
typedef struct s_map
{
	int					height;
	int					width;
	int					player_x;
	int					player_y;
	char				**content;
	int					collectibles;
	int					exits;
}						t_map;

typedef struct s_player
{
	int					heigth;
	int					width;
	t_animation			*idle;
	t_animation			*runing;
	int					player_state;
}						t_player;

typedef struct t_vars
{
	void				*mlx;
	void				*win;
	t_map				*map;
	t_texture			*floor;
	t_texture			*water;
	t_texture			*collectibles;
	t_texture			*exit;
	t_player			*player;
}						t_vars;

int						free_n_returnt(char **str, char *temp, char *msg);
void					free_ifnot_null(char **str);
void					free_content(char **str);
int						check_file_type(char *str);
int						check_one(char *str, char c);
int						err_msg_std(char *msg);
int						count_lines(char *file);
void					get_hw(t_map *map);
t_map					*init_map(void);
int						check_collectibles(t_map *map);
int						check_surrounded(t_map *map);
int						check_rectangular(t_map *map);
int						check_player(t_map *map);
int						check_exits(t_map *map);
int						read_map_files(t_map *map, char *file);
t_map					*map_pop(t_map *map, char *path);
int						check_map(t_map *map);
int						check_path(t_map *map);
t_map					*parse_map(char *path);
char					**copy_map(t_map *map);
int						flood_filling(t_map *map, char **map_copy, int x,
							int y);
int						flood_fill(char **map, int x, int y, int *collectibles);
void					free_map(t_map *map);
int						free_error(char *msg, t_map *map);
t_vars					*init_vars(void);
int						init_mlx(t_vars *vars);
t_texture				*init_txt(void);
char					*int_to_str(int len, int num);
char					*get_img(char *path, int len, int i);
t_animation				*create_node(void *img);
void					add_node(t_animation **head, t_animation *new_node);
t_animation				*load_animation(t_vars *vars, char *path, int h, int w);
void					*load_texture(t_vars *vars, char *path, int h, int w);
t_texture				*create_texture(t_vars *vars, char *path);
t_player				*player_pop(t_vars *vars);
void					draw_texture(t_vars *vars, t_texture *texture, int x,
							int y);
int						make_window(t_vars *vars);
int						render_player(t_vars *vars);
int						render_player_frame(t_vars *vars, t_animation *anim);
void					render_animation(t_vars *vars, t_animation *anim);
void					free_vars(t_vars *vars);
int						on_keypress(int keysym, t_vars *vars);
int						set_player_to_idle(int keysym, t_vars *vars);
int						get_map(t_vars *vars, char *path);
int						get_textures(t_vars *vars);
int						get_player(t_vars *vars);
void					free_player(t_vars *vars, t_player *player);
void					free_texture(t_vars *vars, t_texture *texture);
void					free_animation(t_vars *vars, t_animation *animation);
void					draw_map(t_vars *vars);
#endif