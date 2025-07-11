/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:48:18 by souaammo          #+#    #+#             */
/*   Updated: 2025/05/26 19:48:20 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3D.h"

void	get_wall_side0(t_game *game)
{
	game->draw.wall_hit = game->player.y + (game->draw.distance
			/ cos(game->draw.start_angle - game->angle)) * game->dy;
	game->draw.wall_hit = fmod(game->draw.wall_hit, BLOCK);
	game->draw.texture_x = (int)(game->draw.wall_hit * game->textures.wall_width
			/ BLOCK);
	if (game->draw.texture_x < 0)
		game->draw.texture_x = 0;
	if (game->draw.texture_x >= game->textures.wall_width)
		game->draw.texture_x = game->textures.wall_width - 1;
	if (game->dx > 0)
		game->draw.wall_img = game->textures.no_img;
	else
		game->draw.wall_img = game->textures.so_img;
}

void	get_wall_side1(t_game *game)
{
	game->draw.wall_hit = game->player.x + (game->draw.distance
			/ cos(game->draw.start_angle - game->angle)) * game->dx;
	game->draw.wall_hit = fmod(game->draw.wall_hit, BLOCK);
	game->draw.texture_x = (int)(game->draw.wall_hit * game->textures.wall_width
			/ BLOCK);
	if (game->draw.texture_x < 0)
		game->draw.texture_x = 0;
	if (game->draw.texture_x >= game->textures.wall_width)
		game->draw.texture_x = game->textures.wall_width - 1;
	if (game->dy > 0)
		game->draw.wall_img = game->textures.we_img;
	else
		game->draw.wall_img = game->textures.ea_img;
}

void	draw_door_texture(int y, t_game *game)
{
	if (game->draw.side == 0)
		game->draw.wall_hit = game->player.y + (game->draw.distance
				/ cos(game->draw.start_angle - game->angle)) * game->dy;
	else
		game->draw.wall_hit = game->player.x + (game->draw.distance
				/ cos(game->draw.start_angle - game->angle)) * game->dx;
	game->draw.wall_hit = fmod(game->draw.wall_hit, BLOCK);
	if (game->draw.wall_hit < 0)
		game->draw.wall_hit += BLOCK;
	game->draw.texture_x = (int)(game->draw.wall_hit * game->textures.door_width
			/ BLOCK);
	if (game->draw.texture_x < 0)
		game->draw.texture_x = 0;
	if (game->draw.texture_x >= game->textures.door_width)
		game->draw.texture_x = game->textures.door_width - 1;
	game->draw.texture_y = ((y - game->draw.start_y)
			* game->textures.door_height) / (int)game->draw.wall_height;
	if (game->draw.texture_y < 0)
		game->draw.texture_y = 0;
	if (game->draw.texture_y >= game->textures.door_height)
		game->draw.texture_y = game->textures.door_height - 1;
	game->color = get_pixel_color(game, game->textures.door_img,
			game->draw.texture_x, game->draw.texture_y);
	put_pixel(game->draw.screen_x, y, game->color, game);
}

void	test2(t_game *game)
{
	if (game->draw.side == 0)
		get_wall_side0(game);
	else
		get_wall_side1(game);
}

void	ft_draw_textures(t_game *game)
{
	int	y;

	y = (int)game->draw.start_y - 1;
	while (++y < (int)game->draw.end_y)
	{
		if (y > HEIGHT)
			break ;
		if (game->draw.hit_wall)
		{
			test2(game);
			game->draw.texture_y = ((y - game->draw.start_y)
					* game->textures.wall_height) / (int)game->draw.wall_height;
			if (game->draw.texture_y < 0)
				game->draw.texture_y = 0;
			if (game->draw.texture_y >= game->textures.wall_height)
				game->draw.texture_y = game->textures.wall_height - 1;
			game->color = get_pixel_color(game, game->draw.wall_img,
					game->draw.texture_x, game->draw.texture_y);
			put_pixel(game->draw.screen_x, y, game->color, game);
		}
		else if (game->draw.hit_door)
			draw_door_texture(y, game);
	}
}
