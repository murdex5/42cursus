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
/*   Created: 2025/02/28 15:29:36 by kadferna          #+#    #+#             */
/*   Updated: 2025/02/28 15:29:52 by kadferna         ###   ########.fr       */
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
# define EMPTY 0
# define WALL 1
# define COLLECTABLE 2
# define EXIT 3
# define VISITED 4

/* STRUCTS */

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
	t_map *map;
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
