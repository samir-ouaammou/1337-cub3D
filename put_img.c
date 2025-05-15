# include "cub3D.h"

void    ft_put_img(t_map_config *map)
{
    short   i;
    int     tmp;
    char    *str;
    pthread_t   thread[2];

    pthread_create(&thread[0], NULL, ft_music, "music1.wav");
    i = -1;
    while (++i < 4)
    {
        str = ft_strjoin("/home/souaammo/Desktop/42-cub3D/textures/Samir/image0", ft_itoa(i));
        map->img = mlx_xpm_file_to_image(map->mlx, str, &tmp, &tmp);
        if (map->img)
        {
            mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
            usleep(5000000);
        }
        if (map->img)
        mlx_destroy_image(map->mlx, map->img);
    }
    pthread_create(&thread[1], NULL, ft_music, "music0.wav");
}
