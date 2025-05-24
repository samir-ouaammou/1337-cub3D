/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:52:27 by aahaded           #+#    #+#             */
/*   Updated: 2025/05/24 16:52:28 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_not_wall(double y, double x, t_map_config *g)
{
	return (g->map[(int)(y / BLOCK)][(int)(x / BLOCK)] != '1');
}

int	is_not_door(double y, double x, t_map_config *g)
{
	return (g->map[(int)(y / BLOCK)][(int)(x / BLOCK)] != 'D');
}

int	check_x_collision(t_map_config *g)
{
	if (is_not_wall(g->player.y - 1, g->new_x, g) && is_not_wall(g->player.y
			+ 1, g->new_x - 1, g) && is_not_wall(g->player.y + 1, g->new_x + 1,
			g) && is_not_wall(g->player.y - 1, g->player.x, g)
		&& is_not_wall(g->player.y + 1, g->player.x, g)
		&& is_not_wall(g->player.y + 1, g->player.x - 1, g)
		&& is_not_wall(g->player.y + 1, g->player.x + 1, g)
		&& is_not_door(g->player.y - 1, g->new_x, g) && is_not_door(g->player.y
			+ 1, g->new_x, g) && is_not_door(g->player.y + 1, g->new_x - 1, g)
		&& is_not_door(g->player.y + 1, g->new_x + 1, g)
		&& is_not_door(g->player.y - 1, g->player.x, g)
		&& is_not_door(g->player.y + 1, g->player.x, g)
		&& is_not_door(g->player.y + 1, g->player.x - 1, g)
		&& is_not_door(g->player.y + 1, g->player.x + 1, g))
		return (1);
	return (0);
}

int	check_y_collision(t_map_config *g)
{
	if (is_not_wall(g->new_y - 1, g->player.x, g) && is_not_wall(g->new_y + 1,
			g->player.x, g) && is_not_wall(g->new_y + 1, g->player.x - 1, g)
		&& is_not_wall(g->new_y + 1, g->player.x + 1, g) && is_not_door(g->new_y
			- 1, g->player.x, g) && is_not_door(g->new_y + 1, g->player.x, g)
		&& is_not_door(g->new_y + 1, g->player.x - 1, g) && is_not_door(g->new_y
			+ 1, g->player.x + 1, g))
		return (1);
	return (0);
}

int	mo_player(t_map_config *g)
{
	double	cos_angle;
	double	sin_angle;

	cos_angle = cos(g->angle);
	sin_angle = sin(g->angle);
	g->new_x = g->player.x;
	g->new_y = g->player.y;
	if (g->player.left_rotate)
		g->angle -= SPEED_CAMERA;
	if (g->player.right_rotate)
		g->angle += SPEED_CAMERA;
	mo_player_u(g, cos_angle, sin_angle);
	if (check_x_collision(g))
		g->player.x = g->new_x;
	if (check_y_collision(g))
		g->player.y = g->new_y;
	draw_map(g);
	return (0);
}
