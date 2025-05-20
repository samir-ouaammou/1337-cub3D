# include "../includes/cub3D.h"

void    ft_put_img(t_map_config *map)
{
    short   i;
    int     tmp;
    char    *str;
    pthread_t   thread[2];

    pthread_create(&thread[0], NULL, ft_music, "music/music1.wav");
    pthread_detach(thread[0]);
    i = -1;
    while (++i < 4)
    {
        str = ft_strjoin("/home/souaammo/Desktop/42-cub3D/textures/Samir/image0", ft_itoa(i));
        map->img = mlx_xpm_file_to_image(map->mlx, str, &tmp, &tmp);
        if (map->img)
        {
            mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
            usleep(1000000);
            if (i == 3)
                usleep(3000000);
        }
        if (map->img)
        mlx_destroy_image(map->mlx, map->img);
    }
    pthread_create(&thread[1], NULL, ft_music, "music/music0.wav");
    pthread_detach(thread[1]);
}


void    ft_put_img_to_img(t_map_config *game, int x_offset, int y_offset, int n)
{
    void    *player_img;
	int     player_width;
	int     player_height;
	int     x = -1, y = -1;
	int     color;

    void *img2 = ft_strdup((char *)game->img);

    int i;

    if (n == 1)
        i = n++;
    else
        i = 2;
    while (++i <= n)
    {
        player_img = mlx_xpm_file_to_image(game->mlx, ft_strjoin("textures/player/img", ft_itoa(i)), &player_width, &player_height);
        if (!player_img)
            return ;

        x = -1;
        y = -1;
        while (++y < player_height)
        {
            x = -1;
            while (++x < player_width)
            {
                color = get_pixel_color(player_img, x, y);
                if (color != 0xff000000)
                    put_pixel(x + x_offset, y + y_offset, color, game);
            }
        }
        mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
        usleep(10000);
    }
}
