#include "so_long.h"

char *get_path(char *main, int frame, char *ext, char *path)
{
    int i;
    int j;
    int fd;

    path = malloc(sizeof(char) * (ft_strlen(main) + ft_strlen(ext) + 2));
    i = 0;
    j = 0;
    while (main[j] != '\0')
        path[i++] = main[j++];
    j = 0;
    path[i++] = frame + '0';
    while (ext[j] != '\0')
        path[i++] = ext[j++];
    path[i] = '\0';
    fd = open(path, O_RDONLY);
    if (fd < 0 && path != NULL)
    {
        free(path);
        return (NULL);
    }
    else
    {
        close(fd);
        return (path);
    }
}

void add_frames_helper(t_vars *vars, char *path, t_animation *sprite)
{
    t_animation *temp;

    temp = malloc(sizeof(t_animation));
    if (!temp)
        free_animation(temp);
}

void add_frames(t_vars *vars, char *path, t_animation *sprite)
{
    sprite->img = mlx_xpm_file_to_image(vars->mlx, path, &sprite->w, &sprite->h);
}