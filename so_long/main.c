
#include "so_long.h"


int	main(int argc, char **argv)
{
	t_data data;
	t_map *map;
	int i;

	if (argc != 2)
		return (1);
	map = parsing_map(argv[1]);
	i = 0;
	while (i < map->height)
	{
		ft_printf("%s\n", map->content[i]);
		i++;
	}
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	free_map(map);
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