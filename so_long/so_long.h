/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/03/03 14:09:47 by kadferna          #+#    #+#             */
/*   Updated: 2025/03/03 14:09:49 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "my_headers/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Data Types */
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

/* STRUCTS */

typedef struct s_animation
{
	void *img;
	int w;
	int h;
	struct s_animation *next;
} t_animation;
typedef struct s_player
{
	t_animation *idle;
	t_animation *run;
	int w;
	int h;
	int x;
	int y;
	struct s_player *next;
} t_player;

typedef struct s_box
{
	int m_min;
	int m_max;
	int m_bd;
	int bd;
	int min;
	int max;
} t_box;

typedef struct s_vars
{
	void *mlx;
	void *win;
	t_map *map;
	t_player *player;
} t_vars;
typedef struct s_map
{
	char **content;
	int width;
	int height;
	int player_count;
	int exit_count;
	int collectables;
	int player_x;
	int player_y;
} t_map;

int	check_file_type(char *file, char *type);
int	on_keypress(int keysym, t_vars *vars);
int	on_destroy(t_vars *data);
int	check_path(t_map *map);
int	error_message(char *msg);
int	if_map_rectangled(t_map *map);
int	if_map_sorrounded(t_map *map);
int	check_map_contents(t_map *map);
int	check_map(t_map *map);
t_map	*parsing_map(char *file);
void	clean_up(t_map *map);
char	*get_path(char *main, int frame, char *ext, char *path);
void	free_map(t_map *map);
void	free_map_content(char **content, int height);
void	free_animation(t_animation *anime, t_vars *vars);
void	free_player(t_player *p, t_vars *vars);
void	free_vars(t_vars *vars);
#endif
