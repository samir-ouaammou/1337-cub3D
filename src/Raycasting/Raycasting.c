/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:43:03 by aahaded           #+#    #+#             */
/*   Updated: 2025/05/24 16:43:04 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	calculate_ray_distance(t_game *game)
{
	double	player_block_x;
	double	player_block_y;

	if (game->draw.side == 0)
	{
		player_block_x = game->player.x / BLOCK;
		if (game->step_x < 0)
			game->draw.distance = (game->map_x + 1 - player_block_x) * BLOCK;
		else
			game->draw.distance = (game->map_x - player_block_x) * BLOCK;
		game->draw.distance = fabs(game->draw.distance / game->dx);
	}
	else
	{
		player_block_y = game->player.y / BLOCK;
		if (game->step_y < 0)
			game->draw.distance = (game->map_y + 1 - player_block_y) * BLOCK;
		else
			game->draw.distance = (game->map_y - player_block_y) * BLOCK;
		game->draw.distance = fabs(game->draw.distance / game->dy);
	}
}

int	draw_loop(t_game *game)
{
	clear_image(game);
	game->ray_salib = game->angle - FOV / 2;
	game->ray_mojab = game->angle + FOV / 2;
	game->draw.start_angle = game->ray_salib;
	game->draw.screen_x = 0;
	while (game->draw.start_angle < game->ray_mojab)
	{
		game->dx = cos(game->draw.start_angle);
		game->dy = sin(game->draw.start_angle);
		initialize_ray_steps(game);
		cast_single_ray(game);
		draw_sky_and_floor(game);
		calculate_ray_distance(game);
		game->draw.distance = game->draw.distance * cos(game->draw.start_angle
				- game->angle);
		game->draw.wall_height = (BLOCK * HEIGHT) / game->draw.distance;
		game->draw.start_y = (HEIGHT / 2) - (game->draw.wall_height / 2);
		game->draw.end_y = (HEIGHT / 2) + (game->draw.wall_height / 2);
		ft_draw_textures(game);
		game->draw.screen_x++;
		game->draw.start_angle += 0.0009;
	}
	mo_player(game);
	ft_put_img_to_img(game, 400, 200, 1);
	return (0);
}

int	mouse_move(int x, int y, t_game *g)
{
	(void)y;
	g->angle += (x - WIDTH / 2) * 0.0001;
	mlx_mouse_move(g->mlx, g->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}

int	raycasting(t_game *map)
{
	init(map);
	mlx_hook(map->win, MotionNotify, PointerMotionMask, mouse_move, map);
	mlx_loop_hook(map->mlx, draw_loop, map);
	mlx_hook(map->win, KeyPress, KeyPressMask, key_press, map);
	mlx_hook(map->win, KeyRelease, KeyReleaseMask, key_release, map);
	mlx_loop(map->mlx);
	return (0);
}
