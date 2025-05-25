/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:45:44 by aahaded           #+#    #+#             */
/*   Updated: 2025/05/24 16:45:45 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init(t_game *g)
{
	mlx_mouse_hide(g->mlx, g->win);
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->data_pixel = mlx_get_data_addr(g->img, &g->bpp, &g->size_line,
			&g->endian);
	g->textures.wall_img = mlx_xpm_file_to_image(g->mlx, "./wall.xpm",
			&g->textures.wall_width, &g->textures.wall_height);
	g->textures.door_img = mlx_xpm_file_to_image(g->mlx,
			"./textures/image.xpm/D_img", &g->textures.door_width,
			&g->textures.door_height);
	init_player(g);
}

void	put_pixel(int x, int y, int color, t_game *g)
{
	int	index;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	index = y * g->size_line + x * (g->bpp / 8);
	g->data_pixel[index] = color & 0xFF;
	g->data_pixel[index + 1] = (color >> 8) & 0xFF;
	g->data_pixel[index + 2] = (color >> 16) & 0xFF;
}

int	get_pixel_color(void *img, int x, int y)
{
	char	*data;
	int		index;
	int		color;

	int bpp, size_line, endian;
	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	index = y * size_line + x * (bpp / 8);
	color = *(int *)(data + index);
	return (color);
}

void	draw_tile(t_game *g, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < BLOCK)
	{
		j = 0;
		while (j < BLOCK)
		{
			put_pixel(x + j, y + i, color, g);
			j++;
		}
		i++;
	}
}

void	clear_image(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, 0, game);
			x++;
		}
		y++;
	}
}
