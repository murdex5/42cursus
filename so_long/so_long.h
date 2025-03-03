/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
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

typedef struct s_vars
{
	void *mlx;
	void *win;
	int box_x;
	int box_y;
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

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
} t_data;

int	check_file_type(char *file, char *type);
int	on_keypress(int keysym, t_data *data);
int	on_destroy(t_data *data);
int	check_path(t_map *map);
int	error_message(char *msg);
int	if_map_rectangled(t_map *map);
int	if_map_sorrounded(t_map *map);
int	check_map_contents(t_map *map);
void	free_map(t_map *map);
int	check_map(t_map *map);
t_map	*parsing_map(char *file);
void	clean_up(t_map *map);
void	free_map_content(char **content, int height);
void	free_mlx_pointer(t_data *data);
#endif
