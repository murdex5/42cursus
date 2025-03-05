#include "so_long.h"

void load_animation_run(t_vars *vars, t_animation *sprite)
{
    static int i;
    char *path;

    path = NULL;
    while (1)
    {
        path = get_path("./assets/player_idle/player_run_down/", i, ".xpm", path);
        if (path == NULL)
        {
            vars->player->idle = i;
            break;
        }
        else
        {
            
        }
    } 
}
