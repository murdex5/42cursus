
#include "so_long.h"


int	main(int argc, char **argv)
{
	t_data *data;

	if (argc != 2)
		return (1);
	data->map = parsing_map(argv[1]);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 600, 400, "hi :)");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 1);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data->mlx_ptr);
	ft_printf("%s\n", data->map->content[1]);
	free_mlx_pointer(data);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_map *map;

// 	if (argc != 2)
// 		return (1);
// 	map = parsing_map(argv[1]);
// 	free_map(map);
// 	return (0);
// }