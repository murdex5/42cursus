
#include "so_long.h"


int	main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
		return (1);
	data.map = parsing_map(argv[1]);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr || !data.map)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 500, "sup");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		&data);
	mlx_loop(data.mlx_ptr);
	clean_up(data.map);
	free(data.mlx_ptr);
	free(data.win_ptr);
	return (0);
}
