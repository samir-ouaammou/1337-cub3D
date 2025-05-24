/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:45:55 by aahaded           #+#    #+#             */
/*   Updated: 2025/05/24 16:45:56 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	test(t_map_config *game)
{
	game->draw.side = 0;
	game->draw.hit_wall = 0;
	game->draw.hit_door = 0;
}

void	cast_single_ray(t_map_config *game)
{
	test(game);
	while (1)
	{
		if (game->dis_x < game->dis_y)
		{
			game->dis_x += fabs(BLOCK / game->dx);
			game->map_x += game->step_x;
			game->draw.side = 0;
		}
		else
		{
			game->dis_y += fabs(BLOCK / game->dy);
			game->map_y += game->step_y;
			game->draw.side = 1;
		}
		if (game->map[game->map_y][game->map_x] == '1'
			|| game->map[game->map_y][game->map_x] == 'D')
		{
			if (game->map[game->map_y][game->map_x] == '1')
				game->draw.hit_wall = 1;
			else if (game->map[game->map_y][game->map_x] == 'D')
				game->draw.hit_door = 1;
			break ;
		}
	}
}
