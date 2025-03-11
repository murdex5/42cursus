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

/* DATA TYPES */

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

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
	t_map				*map;
}						t_vars;

int						count_lines(char *file);
int						check_file_type(char *file, char *type);
int						error_message(char *msg);
int						alloc_mem(t_map *map, int line_count);
char					**copy_map(t_map *map);
int						flood_fill(char **map, int x, int y, int *collectibles);
int						read_map_file(t_map *map, char *file);
int						store_player_position(t_map *map);
void					free_map(t_map *map);
void					free_map_content(char **content, int height);
int						free_str(char **content, int i);
int						check_map(t_map *map);
t_map					*parsing_map(char *file);
#endif