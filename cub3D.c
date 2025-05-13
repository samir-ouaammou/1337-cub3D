#include "cub3D.h"

void    *ft_music(void *arg)
{
    SDL_Init(SDL_INIT_AUDIO);
    SDL_AudioSpec wav_spec;
    Uint32 wav_length;
    Uint8 *wav_buffer;

    SDL_LoadWAV((char *)arg, &wav_spec, &wav_buffer, &wav_length);

    SDL_OpenAudio(&wav_spec, NULL);

    SDL_PauseAudio(0);
    SDL_QueueAudio(1, wav_buffer, wav_length);

    SDL_Delay(15000);

    SDL_CloseAudio();
    SDL_FreeWAV(wav_buffer);
    SDL_Quit();
    return (NULL);
}

void    ft_put_img(t_map_config *map)
{
    short   i;
    int     tmp;
    char    *str;
    pthread_t   thread[2];

    pthread_create(&thread[0], NULL, ft_music, "music1.wav");
    i = -1;
    while (++i < 40)
    {
        str = ft_strjoin("/home/souaammo/Desktop/42-cub3D/textures/Samir/img", ft_itoa(i));
        map->img = mlx_xpm_file_to_image(map->mlx, str, &tmp, &tmp);
        if (map->img)
        {
            mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
            usleep(400000);
        }
        if (map->img)
        mlx_destroy_image(map->mlx, map->img);
    }
    pthread_create(&thread[1], NULL, ft_music, "music0.wav");
}

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

    map->win = mlx_new_window(map->mlx, 1280, 600, "cub3D");
    ft_put_img(map);
    mlx_loop(map->mlx);

    // ------------------------------------------------------------------------------------

    ft_exit(0);
    return (0);
}