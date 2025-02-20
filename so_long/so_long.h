#ifndef SO_LONG_H
# define SO_LONG_H

# include "minlibx-linux/mlx.h"
# include "my_headers/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

typedef struct s_vars
{
	void *mlx;
	void *win;
} t_vars;

typedef struct s_map_dims
{
	int width;
	int height;
} t_map_dims;

int	check_file_type(char *file, char *type);
t_map_dims	parsing_map(char *file);
int	check_map(char *file);

#endif