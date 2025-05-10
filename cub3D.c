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

    // ------------------------------------------------------------------------------------
    //printf("player:  [%d\t%d]\n", map->player_x, map->player_y);
    //printf("size:    [%d\t%d]\n", map->map_height, map->map_width);
    //printf("color f: [%d\t%d\t%d]\n", map->floor_color[0], map->floor_color[1], map->floor_color[2]);
    //printf("color c: [%d\t%d\t%d]\n", map->ceiling_color[0], map->ceiling_color[1], map->ceiling_color[2]);

    //printf("map :\n");
    //short i = 0;
    //while (map->map[i])
    //    printf("%s\n", map->map[i++]);
    // ------------------------------------------------------------------------------------

    ft_exit(0);
    return (0);
}