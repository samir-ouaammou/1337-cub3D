#include "cub3D.h"

int main(int ac, char **av)
{
    t_map_config    *map;

    if (ac != 2)
    {
        write (2, "Error\nMap not found — please ensure the map is", 48);
        write(2, " correctly defined and follows the required format.\n", 52);
        exit (-1);
    }
    map = ft_malloc(sizeof(t_map_config));
    if (!map)
        ft_print_error("Error\nMemory allocation failed (malloc)\n");
    ft_init_map_config(map);
    map->mlx = NULL;
    map->mlx = mlx_init();
    if (!map->mlx)
        ft_print_error("Error\nmlx_init\n");
    map = ft_parsing_map_file(map, av[1]);
    map->win = mlx_new_window(map->mlx, 1280, 600, "cub3D");
    // ft_put_img(map); // 
    raycasting(map);
    mlx_loop(map->mlx);
    ft_exit(0);
    return (0);
}
