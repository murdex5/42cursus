
#include "so_long.h"


// int	main(int argc, char **argv)
// {
// 	t_data data;
// 	t_map *map;
// 	int *img_ptr;
// 	int img_width;
// 	int img_height;

// 	if (argc != 2)
// 		return (1);
// 	map = parsing_map(argv[1]);
// 	img_width = 288;
// 	img_height = 240;
// 	data.mlx_ptr = mlx_init();
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, img_width, img_height, "hi :)");
// 	if (!data.win_ptr)
// 		return (free(data.mlx_ptr), 1);
// 	img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/Level_0__path.xpm", &img_width, &img_height);
// 	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img_ptr, img_width, img_height);
// 	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
// 	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
// 	mlx_loop(data.mlx_ptr);
// 	free(img_ptr);
// 	free_map(map);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	t_map *map;

// 	if (argc != 2)
// 		return (1);
// 	map = parsing_map(argv[1]);
// 	free_map(map);
// 	return (0);
// }




int main(int argc, char **argv) {
    t_data data;
    t_map *map;
    int img_width, img_height;

    if (argc != 2)
        return (1);

    map = parsing_map(argv[1]);
    if (!map) {
        fprintf(stderr, "Error: parsing_map failed\n");
        return 1;
    }

    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr) {
        fprintf(stderr, "Error: mlx_init failed\n");
        free_map(map);
        return 1;
    }

    data.win_ptr = mlx_new_window(data.mlx_ptr, 288, 240, "hi :)");
    if (!data.win_ptr) {
        fprintf(stderr, "Error: mlx_new_window failed\n");
        mlx_destroy_display(data.mlx_ptr); // or mlx_destroy_display
        free_map(map);
        return 1;
    }

    data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/House.xpm", &img_width, &img_height);
    if (!data.img_ptr) {
        fprintf(stderr, "Error: mlx_xpm_file_to_image failed\n");
        mlx_destroy_window(data.mlx_ptr, data.win_ptr);
        mlx_destroy_display(data.mlx_ptr); // or mlx_destroy_display
        free_map(map);
        return 1;
    }

    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0); // Draw at (0, 0)

    mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
    mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

    mlx_loop(data.mlx_ptr);

    mlx_destroy_image(data.mlx_ptr, data.img_ptr); // Use mlx_destroy_image
    mlx_destroy_window(data.mlx_ptr, data.win_ptr);
    mlx_destroy_display(data.mlx_ptr); // or mlx_destroy_display
    free_map(map);

    return (0);
}
