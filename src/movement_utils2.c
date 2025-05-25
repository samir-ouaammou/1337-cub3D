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
	double	dx;
	double	dy;
	double	dx_t;
	double	dy_t;

	dx = g->player.x + cos(g->angle) * 10;
	dy = g->player.y + sin(g->angle) * 10;
	dx_t = g->player.x + cos(g->angle) * 5;
	dy_t = g->player.y + sin(g->angle) * 5;
	return (g->map[(int)(dy / BLOCK)][(int)(dx / BLOCK)] == c
		|| g->map[(int)(dy_t / BLOCK)][(int)(dx_t / BLOCK)] == c);
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
