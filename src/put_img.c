/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:46:01 by souaammo          #+#    #+#             */
/*   Updated: 2025/05/26 19:46:02 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_put_img(t_game *map)
{
	int			tmp;
	int			i;
	pthread_t	thread;

	pthread_create(&thread, NULL, ft_music, "music/music1.wav");
	pthread_detach(thread);
	i = -1;
	while (++i < 2)
	{
		map->img = mlx_xpm_file_to_image(map->mlx,
				ft_strjoin("./textures/image0", ft_itoa(i)), &tmp, &tmp);
		if (map->img)
		{
			mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
			mlx_destroy_image(map->mlx, map->img);
			usleep(2000000);
		}
	}
}

int	ft_get_start(t_game *game, int *end)
{
	if (*end == 1)
		game->index.i = (*end)++;
	else
		game->index.i = 2;
	return (game->index.i);
}

void	ft_put_img_to_img(t_game *game, int x_offset,
	int y_offset, int end)
{
	game->index.i = ft_get_start(game, &end);
	while (++game->index.i <= end)
	{
		game->image.img = mlx_xpm_file_to_image(game->mlx, ft_strjoin
				("textures/P_img", ft_itoa(game->index.i)),
				&game->image.width, &game->image.heigth);
		if (!game->image.img)
			return ;
		game->index.y = -1;
		while (++game->index.y < game->image.heigth)
		{
			game->index.x = -1;
			while (++game->index.x < game->image.width)
			{
				game->image.color = get_pixel_color(game, game->image.img,
						game->index.x, game->index.y);
				if (game->image.color != 0xff000000)
					put_pixel(game->index.x + x_offset, game->index.y
						+ y_offset, game->image.color, game);
			}
		}
		mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
		mlx_destroy_image(game->mlx, game->image.img);
		usleep(10000);
	}
}
