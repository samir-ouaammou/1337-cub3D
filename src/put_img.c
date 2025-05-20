# include "../includes/cub3D.h"

void    ft_put_img(t_map_config *map)
{
    int     tmp;
    pthread_t   thread[2];

    pthread_create(&thread[0], NULL, ft_music, "music/music1.wav");
    pthread_detach(thread[0]);
    map->index.i = -1;
    while (++map->index.i < 4)
    {
        map->strs.str = ft_strjoin("./textures/image.img/image0", ft_itoa(map->index.i));
        map->img = mlx_xpm_file_to_image(map->mlx, map->strs.str, &tmp, &tmp);
        if (map->img)
        {
            mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
            usleep(1000000);
            if (map->index.i == 3)
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
    if (n == 1)
        game->index.i = n++;
    else
        game->index.i = 2;
    while (++game->index.i <= n)
    {
        game->image.img = mlx_xpm_file_to_image(game->mlx, ft_strjoin("textures/image.xpm/P_img", ft_itoa(game->index.i)), &game->image.width, &game->image.heigth);
        if (!game->image.img)
            return ;
        game->index.y = -1;
        while (++game->index.y < game->image.heigth)
        {
            game->index.x = -1;
            while (++game->index.x < game->image.width)
            {
                game->image.color = get_pixel_color(game->image.img, game->index.x, game->index.y);
                if (game->image.color != 0xff000000)
                    put_pixel(game->index.x + x_offset, game->index.y + y_offset, game->image.color, game);
            }
        }
        mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
        usleep(10000);
    }
}
