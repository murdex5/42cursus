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
	int		widht;
	int		player_pos[2];
	char	**content;
	int		collectibles;
	int		exits;
}			t_map;

int			free_n_returnt(char **str, char *temp, char *msg);
int			check_file_type(char *str);
int			err_msg_std(char *msg);
int			count_lines(char *file);
int			read_map_files(t_map *map, char *file);
t_map		*check_map(char *path);
#endif