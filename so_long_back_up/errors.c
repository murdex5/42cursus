#include "so_long.h"

void	malloc_er(t_vars *vars)
{
	ft_printf("Not enough memory to Malloc\n");
	free_vars(vars);
	exit(1);
}