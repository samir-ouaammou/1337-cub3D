/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:45:02 by aahaded           #+#    #+#             */
/*   Updated: 2025/05/24 16:45:03 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_player_angle(t_game *g, int j, int i)
{
	if (g->map[i][j] == 'N')
		g->angle = -M_PI / 2;
	else if (g->map[i][j] == 'S')
		g->angle = M_PI / 2;
	else if (g->map[i][j] == 'W')
		g->angle = M_PI;
	else if (g->map[i][j] == 'E')
		g->angle = 0;
}

void	init_player(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'W' || g->map[i][j] == 'N'
				|| g->map[i][j] == 'S' || g->map[i][j] == 'E')
			{
				g->player.x = j * BLOCK + BLOCK / 2;
				g->player.y = i * BLOCK + BLOCK / 2;
				set_player_angle(g, j, i);
				g->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			put_pixel(g->player.x + j, g->player.y + i, 0xFF0000, g);
			j++;
		}
		i++;
	}
}

int	draw_map(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == '1')
				draw_tile(g, j * BLOCK, i * BLOCK, 0x0000FF);
			else if (g->map[i][j] == 'D')
				draw_tile(g, j * BLOCK, i * BLOCK, 0xFF0000);
			else if (g->map[i][j] == 'O')
				draw_tile(g, j * BLOCK, i * BLOCK, 0x00FF00);
			else
				draw_tile(g, j * BLOCK, i * BLOCK, 0x000000);
			j++;
		}
		i++;
	}
	draw_player(g);
	return (0);
}

void	ft_free_image(t_game *game)
{
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->textures.img)
		mlx_destroy_image(game->mlx, game->textures.img);
	if (game->textures.door_img)
		mlx_destroy_image(game->mlx, game->textures.door_img);
	if (game->textures.wall_img)
		mlx_destroy_image(game->mlx, game->textures.wall_img);
	if (game->textures.no_img)
		mlx_destroy_image(game->mlx, game->textures.no_img);
	if (game->textures.so_img)
		mlx_destroy_image(game->mlx, game->textures.so_img);
	if (game->textures.we_img)
		mlx_destroy_image(game->mlx, game->textures.we_img);
	if (game->textures.ea_img)
		mlx_destroy_image(game->mlx, game->textures.ea_img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_exit(0);
}
