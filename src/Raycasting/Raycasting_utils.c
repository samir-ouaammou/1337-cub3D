/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:10:52 by aahaded           #+#    #+#             */
/*   Updated: 2025/05/26 18:14:46 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3D.h"

void	draw_sky_and_floor(t_game *game)
{
	double	y;

	y = HEIGHT / 2;
	while (y > 0)
	{
		put_pixel(game->draw.screen_x, y, color_c(game), game);
		y--;
	}
	y = HEIGHT / 2;
	while (y < WIDTH)
	{
		put_pixel(game->draw.screen_x, y, color_f(game), game);
		y++;
	}
}

void	setup_y_direction(t_game *game)
{
	double	pl_y;

	pl_y = game->player.y;
	if (game->dy < 0)
	{
		game->step_y = -1;
		game->dis_y = fabs(((pl_y - (game->map_y * BLOCK)) / BLOCK) * (BLOCK
					/ game->dy));
	}
	else
	{
		game->step_y = 1;
		game->dis_y = fabs(((pl_y - ((game->map_y + 1) * BLOCK)) / BLOCK)
				* (BLOCK / game->dy));
	}
}

void	initialize_ray_steps(t_game *game)
{
	double	pl_x;

	pl_x = game->player.x;
	game->map_x = (int)(pl_x / BLOCK);
	game->map_y = (int)(game->player.y / BLOCK);
	game->step_x = 0;
	game->step_y = 0;
	game->dis_x = 0.0;
	game->dis_y = 0.0;
	if (game->dx < 0)
	{
		game->step_x = -1;
		game->dis_x = fabs(((pl_x - (game->map_x * BLOCK)) / BLOCK) * (BLOCK
					/ game->dx));
	}
	else
	{
		game->step_x = 1;
		game->dis_x = fabs(((pl_x - ((game->map_x + 1) * BLOCK)) / BLOCK)
				* (BLOCK / game->dx));
	}
	setup_y_direction(game);
}

int	color_f(t_game *game)
{
	int	f1;
	int	f2;
	int	f3;

	f1 = game->floor_color[0];
	f2 = game->floor_color[1];
	f3 = game->floor_color[2];
	return ((f1 << 16) | (f2 << 8) | f3);
}

int	color_c(t_game *game)
{
	int	c1;
	int	c2;
	int	c3;

	c1 = game->ceiling_color[0];
	c2 = game->ceiling_color[1];
	c3 = game->ceiling_color[2];
	return ((c1 << 16) | (c2 << 8) | c3);
}
