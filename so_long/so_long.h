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
typedef struct s_map
{
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	char	**content;
	int		collectibles;
	int		exits;
}			t_map;

typedef struct t_vars
{
	void	*mlx;
	void	*win;
	t_map	*map;
}			t_vars;

int			free_n_returnt(char **str, char *temp, char *msg);
void		free_ifnot_null(char **str);
void		free_content(char **str);
int			check_file_type(char *str);
int			check_one(char *str, char c);
int			err_msg_std(char *msg);
int			count_lines(char *file);
void		get_hw(t_map *map);
t_map		*init_map(void);
int			check_collectibles(t_map *map);
int			check_surrounded(t_map *map);
int			check_rectangular(t_map *map);
int			check_player(t_map *map);
int			check_exits(t_map *map);
int			read_map_files(t_map *map, char *file);
t_map		*map_pop(t_map *map, char *path);
int			check_map(t_map *map);
int			check_path(t_map *map);
t_map		*parse_map(char *path);
char		**copy_map(t_map *map);
int			flood_filling(t_map *map, char **map_copy, int x, int y);
int			flood_fill(char **map, int x, int y, int *collectibles);
void		free_map(t_map *map);
int			free_error(char *msg, t_map *map);
t_vars		*init_vars(void);
int			init_mlx(t_vars *vars);
int			make_window(t_vars *vars);
void		free_vars(t_vars *vars);
int			on_keypress(int keysym, t_vars *vars);
int			get_map(t_vars *vars, char *path);
#endif