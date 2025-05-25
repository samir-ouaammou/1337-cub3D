/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:52:50 by aahaded           #+#    #+#             */
/*   Updated: 2025/05/24 16:52:51 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	handle_door_interaction(t_game *g, int keycode)
{
	int	player_map_x;
	int	player_map_y;

	player_map_x = (int)(g->player.x / BLOCK);
	player_map_y = (int)(g->player.y / BLOCK);
	if ((keycode == 'E' || keycode == 'e') && is_looking_at_door(g, 'D')
		&& g->close_kay == 0 && g->map[player_map_y][player_map_x] != 'D')
	{
		if (g->map[(int)(g->b3id_y / BLOCK)][(int)(g->b3id_x / BLOCK)] == 'D')
			g->map[(int)(g->b3id_y / BLOCK)][(int)(g->b3id_x / BLOCK)] = 'O';
		else if (g->map[(int)(g->a9rib_y / BLOCK)][(int)(g->a9rib_x
				/ BLOCK)] == 'D')
			g->map[(int)(g->a9rib_y / BLOCK)][(int)(g->a9rib_x / BLOCK)] = 'O';
	}
	else if ((keycode == 'E' || keycode == 'e') && is_looking_at_door(g, 'O')
		&& g->close_kay == 0 && g->map[player_map_y][player_map_x] != 'O')
	{
		if (g->map[(int)(g->b3id_y / BLOCK)][(int)(g->b3id_x / BLOCK)] == 'O')
			g->map[(int)(g->b3id_y / BLOCK)][(int)(g->b3id_x / BLOCK)] = 'D';
		else if (g->map[(int)(g->a9rib_y / BLOCK)][(int)(g->a9rib_x
				/ BLOCK)] == 'O')
			g->map[(int)(g->a9rib_y / BLOCK)][(int)(g->a9rib_x / BLOCK)] = 'D';
	}
}

int	key_press(int keycode, t_game *g)
{
	g->b3id_x = g->player.x + cos(g->angle) * 10;
	g->b3id_y = g->player.y + sin(g->angle) * 10;
	g->a9rib_x = g->player.x + cos(g->angle) * 5;
	g->a9rib_y = g->player.y + sin(g->angle) * 5;
	if (keycode == ESC_KEY)
	{
		ft_free_image(g);
		ft_exit(0);
	}
	handle_door_interaction(g, keycode);
	handle_key_press(g, keycode);
	return (0);
}

void	key_release_u(int keycode, t_game *g)
{
	if (keycode == LEFT)
		g->player.left_rotate = false;
	else if (keycode == RIGHT)
		g->player.right_rotate = false;
}

int	key_release(int keycode, t_game *g)
{
	if (keycode == SPACE)
		ft_put_img_to_img(g, 400, 195, 3);
	if (keycode == A)
	{
		g->close_kay = 0;
		g->player.key_left = false;
	}
	else if (keycode == D)
	{
		g->close_kay = 0;
		g->player.key_right = false;
	}
	else if (keycode == W)
	{
		g->close_kay = 0;
		g->player.key_up = false;
	}
	else if (keycode == S)
	{
		g->close_kay = 0;
		g->player.key_down = false;
	}
	key_release_u(keycode, g);
	return (0);
}

void	mo_player_u(t_game *g, double cos_angle, double sin_angle)
{
	if (g->player.key_up)
	{
		g->new_x += cos_angle * SPEED_PLAYER;
		g->new_y += sin_angle * SPEED_PLAYER;
	}
	if (g->player.key_down)
	{
		g->new_x -= cos_angle * SPEED_PLAYER;
		g->new_y -= sin_angle * SPEED_PLAYER;
	}
	if (g->player.key_left)
	{
		g->new_x += sin_angle * SPEED_PLAYER;
		g->new_y -= cos_angle * SPEED_PLAYER;
	}
	if (g->player.key_right)
	{
		g->new_x -= sin_angle * SPEED_PLAYER;
		g->new_y += cos_angle * SPEED_PLAYER;
	}
}
