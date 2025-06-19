/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:53:13 by aahaded           #+#    #+#             */
/*   Updated: 2025/05/24 16:53:15 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3D.h"

int	is_looking_at_door(t_game *g, int c)
{
	double	b3id_x;
	double	b3id_y;
	double	a9rib_x;
	double	a9rib_y;

	b3id_x = g->player.x + cos(g->angle) * 10;
	b3id_y = g->player.y + sin(g->angle) * 10;
	a9rib_x = g->player.x + cos(g->angle) * 5;
	a9rib_y = g->player.y + sin(g->angle) * 5;
	return (g->map[(int)(b3id_y / BLOCK)][(int)(b3id_x / BLOCK)] == c
		|| g->map[(int)(a9rib_y / BLOCK)][(int)(a9rib_x / BLOCK)] == c);
}

void	handle_key_press(t_game *g, int keycode)
{
	if (keycode == A)
	{
		g->close_kay = 1;
		g->player.key_left = true;
	}
	else if (keycode == D)
	{
		g->close_kay = 1;
		g->player.key_right = true;
	}
	else if (keycode == W)
	{
		g->close_kay = 1;
		g->player.key_up = true;
	}
	else if (keycode == S)
	{
		g->close_kay = 1;
		g->player.key_down = true;
	}
	else if (keycode == LEFT)
		g->player.left_rotate = true;
	else if (keycode == RIGHT)
		g->player.right_rotate = true;
}
