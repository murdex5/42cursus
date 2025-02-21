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

/* STRUCTS */

typedef struct s_map
{
	int width;
	int height;
} t_map;

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;

int	check_file_type(char *file, char *type);
int	check_map(int argc, char **argv);
int	on_keypress(int keysym, t_data *data);
int	on_destroy(t_data *data);

#endif