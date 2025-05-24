#include "../../includes/cub3D.h"

int	color_f(t_map_config *game)
{
	return ((game->floor_color[0] << 16) | (game->floor_color[1] << 8) | game->floor_color[2]);
}

int	color_c(t_map_config *game)
{
	return ((game->ceiling_color[0] << 16) | (game->ceiling_color[1] << 8) | game->ceiling_color[2]);
}

void	draw_sky_and_floor(t_map_config *game)
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

void	setup_y_direction(t_map_config *game)
{
    double pl_y;
    
    pl_y = game->player.y;
	if (game->dy < 0)
	{
		game->step_y = -1;
		game->dis_y = fabs(((pl_y- (game->map_y * BLOCK)) / BLOCK)
				* (BLOCK / game->dy));
	}
	else
	{
		game->step_y = 1;
		game->dis_y = fabs(((pl_y- ((game->map_y + 1) * BLOCK))
					/ BLOCK) * (BLOCK / game->dy));
	}
}

void	initialize_ray_steps(t_map_config *game)
{
    double pl_x;
    
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
		game->dis_x = fabs(((pl_x - (game->map_x * BLOCK)) / BLOCK)
				* (BLOCK / game->dx));
	}
	else
	{
		game->step_x = 1;
		game->dis_x = fabs(((pl_x- ((game->map_x + 1) * BLOCK))
					/ BLOCK) * (BLOCK / game->dx));
	}
	setup_y_direction(game);
}
