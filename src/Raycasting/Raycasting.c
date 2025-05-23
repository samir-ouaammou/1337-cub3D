#include "../../includes/cub3D.h"

void init_player(t_map_config *g);

void init(t_map_config *g)
{
	// mlx_mouse_hide(g->mlx, g->win);
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->data_pixel = mlx_get_data_addr(g->img, &g->bpp, &g->size_line, &g->endian);
	g->textures.wall_img = mlx_xpm_file_to_image(g->mlx, "./wall.xpm", &g->textures.wall_width, &g->textures.wall_height);
	g->textures.door_img = mlx_xpm_file_to_image(g->mlx, "./textures/image.xpm/D_img", &g->textures.door_width, &g->textures.door_height);
	init_player(g);
}

void put_pixel(int x, int y, int color, t_map_config *g)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;
	int index = y * g->size_line + x * (g->bpp / 8);
	g->data_pixel[index] = color & 0xFF;
	g->data_pixel[index + 1] = (color >> 8) & 0xFF;
	g->data_pixel[index + 2] = (color >> 16) & 0xFF;
}

// void put_pixel(int x, int y, int color, t_map_config *g)
// {
// 	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
// 		return;
// 	int index = y * g->size_line2 + x * (g->bpp2 / 8);
// 	g->data_pixel2[index] = color & 0xFF;
// 	g->data_pixel2[index + 1] = (color >> 8) & 0xFF;
// 	g->data_pixel2[index + 2] = (color >> 16) & 0xFF;
// }

int get_pixel_color(void *img, int x, int y)
{
	char *data;
	int bpp, size_line, endian;
	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	int index = y * size_line + x * (bpp / 8);
	int color = *(int *)(data + index);
	return color;
}

void draw_tile(t_map_config *g, int x, int y, int color)
{
	for (int i = 0; i < BLOCK; i++)
	{
		for (int j = 0; j < BLOCK; j++)
		{
			put_pixel(x + j, y + i, color, g);
		}
	}
}

void init_player(t_map_config *g)
{
	for (int i = 0; g->map[i]; i++)
	{
		for (int j = 0; g->map[i][j]; j++)
		{
			if (g->map[i][j] == 'W' || g->map[i][j] == 'N' ||
				g->map[i][j] == 'S' || g->map[i][j] == 'E')
			{
				g->player.x = j * BLOCK + BLOCK / 2;
				g->player.y = i * BLOCK + BLOCK / 2;
				if (g->map[i][j] == 'N')
					g->angle = -M_PI / 2;
				else if (g->map[i][j] == 'S')
					g->angle = M_PI / 2;
				else if (g->map[i][j] == 'W')
					g->angle = M_PI;
				else if (g->map[i][j] == 'E')
					g->angle = 0;
				g->map[i][j] = '0';
				return;
			}
		}
	}
}

void draw_player(t_map_config *g)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			put_pixel(g->player.x + j, g->player.y + i, 0xFF0000, g);
		}
	}
}

// void draw_test(t_map_config *g)
// {
// 	for (int i = 0; i < 5; i++)
// 	{
// 		for (int j = 0; j < 5; j++)
// 		{
// 			put_pixel(g->player.x + j -0.9, g->player.y + i -1, 0xFF00FF, g);
// 		}
// 	}
// }

int draw_map(t_map_config *g)
{
	for (int i = 0; g->map[i]; i++)
	{
		for (int j = 0; g->map[i][j]; j++)
		{
			if (g->map[i][j] == '1')
				draw_tile(g, j * BLOCK, i * BLOCK, 0x0000FF);
			else if (g->map[i][j] == 'D')
				draw_tile(g, j * BLOCK, i * BLOCK, 0xFF0000);
			else if (g->map[i][j] == 'O')
				draw_tile(g, j * BLOCK, i * BLOCK, 0x00FF00);
			else
				draw_tile(g, j * BLOCK, i * BLOCK, 0x000000);
		}
	}
	// draw_test(g);
	draw_player(g);
	return (0);
}

void	ft_free_image(t_map_config *game)
{
	if (game->img)
    mlx_destroy_image(game->mlx, game->img);
	if (game->textures.img)
		mlx_destroy_image(game->mlx, game->textures.img);
	if (game->textures.door_img)
		mlx_destroy_image(game->mlx, game->textures.door_img);
	if (game->textures.wall_img)
		mlx_destroy_image(game->mlx, game->textures.wall_img);
	if ( game->textures.no_img)
		mlx_destroy_image(game->mlx, game->textures.no_img);
	if ( game->textures.so_img)
		mlx_destroy_image(game->mlx, game->textures.so_img);
	if ( game->textures.we_img)
		mlx_destroy_image(game->mlx, game->textures.we_img);
	if ( game->textures.ea_img)
		mlx_destroy_image(game->mlx, game->textures.ea_img);
	if ( game->win)
		mlx_destroy_window(game->mlx, game->win);
	if ( game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_exit(0);
}

int key_press(int keycode, t_map_config *g)
{
	int player_map_x = (int)(g->player.x / BLOCK);
	int player_map_y = (int)(g->player.y / BLOCK);
	double dx = g->player.x + cos(g->angle) * 10;
	double dy = g->player.y + sin(g->angle) * 10;
	double dx_t = g->player.x + cos(g->angle) * 5;
	double dy_t = g->player.y + sin(g->angle) * 5;

	if (keycode == ESC_KEY)
	{
		ft_free_image(g);
		ft_exit(0);
	}
	if ((keycode == 'E' || keycode == 'e')
		&& (g->map[(int)(dy / BLOCK)][(int)(dx / BLOCK)] == 'D' || g->map[(int)(dy_t / BLOCK)][(int)(dx_t / BLOCK)] == 'D') && g->close_kay == 0
		&& g->map[player_map_y][player_map_x] != 'D')
	{
		if (g->map[(int)(dy / BLOCK)][(int)(dx / BLOCK)] == 'D')
			g->map[(int)(dy / BLOCK)][(int)(dx / BLOCK)] = 'O';
		else if (g->map[(int)(dy_t / BLOCK)][(int)(dx_t / BLOCK)] == 'D')
			g->map[(int)(dy_t / BLOCK)][(int)(dx_t / BLOCK)] = 'O';
	}
	else if ((keycode == 'E' || keycode == 'e')
	&& (g->map[(int)(dy / BLOCK)][(int)(dx / BLOCK)] == 'O' || g->map[(int)(dy_t / BLOCK)][(int)(dx_t / BLOCK)] == 'O') && g->close_kay == 0 &&  g->map[player_map_y][player_map_x] != 'O')
	{
		if (g->map[(int)(dy / BLOCK)][(int)(dx / BLOCK)] == 'O')
			g->map[(int)(dy / BLOCK)][(int)(dx / BLOCK)] = 'D';
		else if (g->map[(int)(dy_t / BLOCK)][(int)(dx_t / BLOCK)] == 'O')
			g->map[(int)(dy_t / BLOCK)][(int)(dx_t / BLOCK)] = 'D';
	}
	else if (keycode == A)
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
	return (0);
}

int key_release(int keycode, t_map_config *g)
{
	if (keycode == SPACE)
		ft_put_img_to_img(g, 400 , 195, 3);
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
	else if (keycode == LEFT)
		g->player.left_rotate = false;
	else if (keycode == RIGHT)
		g->player.right_rotate = false;
	return (0);
}

int mo_player(t_map_config *g)
{
	double cos_angle = cos(g->angle);
	double sin_angle = sin(g->angle);
	double new_x = g->player.x;
	double new_y = g->player.y;

	if (g->player.left_rotate)
		g->angle -= SPEED_CAMERA;
	if (g->player.right_rotate)
		g->angle += SPEED_CAMERA;
	if (g->player.key_up)
	{
		new_x += cos_angle * SPEED_PLAYER;
		new_y += sin_angle * SPEED_PLAYER;
	}
	if (g->player.key_down)
	{
		new_x -= cos_angle * SPEED_PLAYER;
		new_y -= sin_angle * SPEED_PLAYER;
	}
	if (g->player.key_left)
	{
		new_x += sin_angle * SPEED_PLAYER;
		new_y -= cos_angle * SPEED_PLAYER;
	}
	if (g->player.key_right)
	{
		new_x -= sin_angle * SPEED_PLAYER;
		new_y += cos_angle * SPEED_PLAYER;
	}
	if (g->map[(int)((g->player.y - 1) / BLOCK)][(int)(new_x / BLOCK)] != '1'
		&& g->map[(int)((g->player.y + 1) / BLOCK)][(int)(new_x / BLOCK)] != '1'
		&& g->map[(int)((g->player.y + 1) / BLOCK)][(int)((new_x - 1) / BLOCK)] != '1'
		&& g->map[(int)((g->player.y + 1) / BLOCK)][(int)((new_x + 1) / BLOCK)] != '1'
		&& g->map[(int)((g->player.y - 1) / BLOCK)][(int)(g->player.x / BLOCK)] != '1'
		&& g->map[(int)((g->player.y + 1) / BLOCK)][(int)(g->player.x / BLOCK)] != '1'
		&& g->map[(int)((g->player.y + 1) / BLOCK)][(int)((g->player.x - 1) / BLOCK)] != '1'
		&& g->map[(int)((g->player.y + 1) / BLOCK)][(int)((g->player.x + 1) / BLOCK)] != '1'
		&& g->map[(int)((g->player.y - 1) / BLOCK)][(int)(new_x / BLOCK)] != 'D'
		&& g->map[(int)((g->player.y + 1) / BLOCK)][(int)(new_x / BLOCK)] != 'D'
		&& g->map[(int)((g->player.y + 1) / BLOCK)][(int)((new_x - 1) / BLOCK)] != 'D'
		&& g->map[(int)((g->player.y + 1) / BLOCK)][(int)((new_x + 1) / BLOCK)] != 'D'
		&& g->map[(int)((g->player.y - 1) / BLOCK)][(int)(g->player.x / BLOCK)] != 'D'
		&& g->map[(int)((g->player.y + 1) / BLOCK)][(int)(g->player.x / BLOCK)] != 'D'
		&& g->map[(int)((g->player.y + 1) / BLOCK)][(int)((g->player.x - 1) / BLOCK)] != 'D'
		&& g->map[(int)((g->player.y + 1) / BLOCK)][(int)((g->player.x + 1) / BLOCK)] != 'D')
		g->player.x = new_x;
	if (g->map[(int)((new_y - 1) / BLOCK)][(int)(g->player.x / BLOCK)] != '1'
		&& g->map[(int)((new_y + 1) / BLOCK)][(int)(g->player.x / BLOCK)] != '1'
		&& g->map[(int)((new_y + 1) / BLOCK)][(int)((g->player.x - 1) / BLOCK)] != '1'
		&& g->map[(int)((new_y + 1) / BLOCK)][(int)((g->player.x + 1) / BLOCK)] != '1'
		&& g->map[(int)((new_y - 1) / BLOCK)][(int)(g->player.x / BLOCK)] != 'D'
		&& g->map[(int)((new_y + 1) / BLOCK)][(int)(g->player.x / BLOCK)] != 'D'
		&& g->map[(int)((new_y + 1) / BLOCK)][(int)((g->player.x - 1) / BLOCK)] != 'D'
		&& g->map[(int)((new_y + 1) / BLOCK)][(int)((g->player.x + 1) / BLOCK)] != 'D')
		g->player.y = new_y;
	draw_map(g);
	return (0);
}

void clear_image(t_map_config *game)
{
	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++)
			put_pixel(x, y, 0, game);
}

int apply_distance_shading(int color, double distance);


void get_wall_side0(t_map_config *game, double distance, double angle, int *texture_x, void **wall_img)
{
    double wall_hit = game->player.y + (distance / cos(angle - game->angle)) * game->dy;
    wall_hit = fmod(wall_hit, BLOCK);
    *texture_x = (int)(wall_hit * game->textures.wall_width / BLOCK);
    if (*texture_x < 0)
		*texture_x = 0;
    if (*texture_x >= game->textures.wall_width)
		*texture_x = game->textures.wall_width - 1;
    *wall_img = (game->dx > 0) ? game->textures.no_img : game->textures.so_img;
}

void get_wall_side1(t_map_config *game, double distance, double angle, int *texture_x, void **wall_img)
{
    double wall_hit = game->player.x + (distance / cos(angle - game->angle)) * game->dx;
    wall_hit = fmod(wall_hit, BLOCK);
    *texture_x = (int)(wall_hit * game->textures.wall_width / BLOCK);
    if (*texture_x < 0)
		*texture_x = 0;
    if (*texture_x >= game->textures.wall_width)
		*texture_x = game->textures.wall_width - 1;
    *wall_img = (game->dy > 0) ? game->textures.we_img : game->textures.ea_img;
}

void draw_door_texture(int screen_x, int y, double start_y, double wall_height, t_map_config *game, int side, double distance, double angle, double start_angle)
{
    int texture_x, texture_y;
    double wall_hit;
    void *door_img = game->textures.door_img;

    if (side == 0)
        wall_hit = game->player.y + (distance / cos(angle - start_angle)) * game->dy;
    else
        wall_hit = game->player.x + (distance / cos(angle - start_angle)) * game->dx;
    wall_hit = fmod(wall_hit, BLOCK);
    if (wall_hit < 0)
        wall_hit += BLOCK;

    texture_x = (int)(wall_hit * game->textures.door_width / BLOCK);
    if (texture_x < 0)
		texture_x = 0;
    if (texture_x >= game->textures.door_width)
		texture_x = game->textures.door_width - 1;

    texture_y = ((y - start_y) * game->textures.door_height) / (int)wall_height;
    if (texture_y < 0)
		texture_y = 0;
    if (texture_y >= game->textures.door_height)
		texture_y = game->textures.door_height - 1;

    int color = get_pixel_color(door_img, texture_x, texture_y);
    put_pixel(screen_x, y, color, game);
}

void ft_draw_textures(int screen_x, double start_y, double end_y, int hit_wall, int hit_door, int side, double distance, double angle, double wall_height, t_map_config *game)
{
    int color = 0;
    for (int y = (int)start_y; y < (int)end_y; y++)
    {
        if (hit_wall)
        {
            int texture_x;
            void *wall_img;
            if (side == 0)
                get_wall_side0(game, distance, angle, &texture_x, &wall_img);
            else
                get_wall_side1(game, distance, angle, &texture_x, &wall_img);
            int texture_y = ((y - start_y) * game->textures.wall_height) / (int)wall_height;
            if (texture_y < 0) texture_y = 0;
            if (texture_y >= game->textures.wall_height) texture_y = game->textures.wall_height - 1;
            color = get_pixel_color(wall_img, texture_x, texture_y);
        }
        else if (hit_door)
        {
            draw_door_texture(screen_x, y, start_y, wall_height, game, side, distance, angle, game->angle);
            continue;
        }
        put_pixel(screen_x, y, color, game);
    }
}

int color_f(t_map_config *game)
{
	 return (game->floor_color[0] << 16) | (game->floor_color[1] << 8) | game->floor_color[2];
}

int color_c(t_map_config *game)
{
	return (game->ceiling_color[0] << 16) | (game->ceiling_color[1] << 8) | game->ceiling_color[2];
}

int draw_loop(t_map_config *game)
{
	clear_image(game);
	game->ray_salib = game->angle - FOV / 2;
	game->ray_mojab = game->angle + FOV / 2;
	double angle = game->ray_salib;
	int screen_x = 0;
	while (angle < game->ray_mojab)
	{
		game->dx = cos(angle);
		game->dy = sin(angle);
		double player_x = game->player.x;
		double player_y = game->player.y;
		int map_x = (int)(player_x / BLOCK);
		int map_y = (int)(player_y / BLOCK);
		int step_x = 0;
		int step_y = 0;
		double dis_x = 0.0;
		double dis_y = 0.0;
		if (game->dx < 0)
		{
			step_x = -1;
			dis_x = fabs(((player_x - (map_x * BLOCK)) / BLOCK) * (BLOCK / game->dx));
		}
		else
		{
			step_x = 1;
			dis_x = fabs(((player_x - ((map_x + 1) * BLOCK)) / BLOCK) * (BLOCK / game->dx));
		}
		if (game->dy < 0)
		{
			step_y = -1;
			dis_y = fabs(((player_y - (map_y * BLOCK)) / BLOCK) * (BLOCK / game->dy));
		}
		else
		{
			step_y = 1;
			dis_y = fabs(((player_y - ((map_y + 1) * BLOCK)) / BLOCK) * (BLOCK / game->dy));
		}
		int side = 0;
		int hit_wall = 0;
		int hit_door = 0;
		int j = 0;
		while (1)
		{
			if (dis_x < dis_y)
			{
				dis_x += fabs(BLOCK / game->dx);
				map_x += step_x;
				side = 0;
			}
			else
			{
				dis_y += fabs(BLOCK / game->dy);
				map_y += step_y;
				side = 1;
			}
			if (game->map[map_y][map_x] == '1' || game->map[map_y][map_x] == 'D')
			{
				if (game->map[map_y][map_x] == '1')
					hit_wall = 1;
				else if (game->map[map_y][map_x] == 'D')
					hit_door = 1;
				break;
			}
			j++;
		}
		double distance;
		double start_y1 = HEIGHT / 2;
		double end_y1 = 0;
		for (double y = start_y1; y > end_y1; y--)
		{
			put_pixel(screen_x, y, color_c(game), game);
		}
		double start_y2 = HEIGHT / 2;
		double end_y2 = WIDTH;
		for (double y = start_y2; y < end_y2; y++)
		{
			put_pixel(screen_x, y, color_f(game), game);
		}
		if (side == 0)
		{
			double player_BLOCK_x = player_x / BLOCK;
			if (step_x < 0)
				distance = (map_x + 1 - player_BLOCK_x) * BLOCK;
			else
				distance = (map_x - player_BLOCK_x) * BLOCK;
			distance = fabs(distance / game->dx);
		}
		else
		{
			double player_BLOCK_y = player_y / BLOCK;
			if (step_y < 0)
				distance = (map_y + 1 - player_BLOCK_y) * BLOCK;
			else
				distance = (map_y - player_BLOCK_y) * BLOCK;
			distance = fabs(distance / game->dy);
		}
		distance = distance * cos(angle - game->angle);
		double wall_height = (BLOCK * HEIGHT) / distance;
		double start_y = (HEIGHT / 2) - (wall_height / 2);
		double end_y = (HEIGHT / 2) + (wall_height / 2);
		ft_draw_textures(screen_x, start_y, end_y, hit_wall, hit_door, side, distance, angle, wall_height, game); // Samir
		screen_x++;
		angle += 0.0009;
	}
	mo_player(game);
	ft_put_img_to_img(game, 400 , 200, 1);
	return 0;
}

int apply_distance_shading(int color, double distance)
{
	int r = (color >> 16) & 0xFF;
	int g = (color >> 8) & 0xFF;
	int b = color & 0xFF;
	double shade_factor = 0.1 - fmin(distance / (WIDTH * 0.8), 0.8);
	r = (int)(r * shade_factor);
	g = (int)(g * shade_factor);
	b = (int)(b * shade_factor);
	return (r << 16) | (g << 8) | b;
}

int mouse_move(int x, int y, t_map_config *g)
{
	(void)y;
	g->angle += (x - WIDTH / 2) * 0.0001;
	mlx_mouse_move(g->mlx, g->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}

int raycasting(t_map_config *map)
{
	init(map);
	// draw_map(map);
	// for (int i = 0; i < 10; i++)
	// {
	// 	for (int j = 0; j < 10; j++)
	// 	{
	// 		put_pixel(j / 2, i / 2, 255, map);
	// 	}
	// }
	// cs_sound_params_t theme_params;
	// cs_audio_source_t *sound_track;
	// sound_track = cs_load_wav("/home/aahaded/Desktop/cub3d/resources/e1m1.wav", NULL);
	// theme_params = cs_sound_params_default();
	// cs_play_sound(sound_track, theme_params);
	// mlx_mouse_move(map->mlx, map->win, WIDTH / 2, HEIGHT / 2);

	// int floot_index = 100;
	// int floot_pos = (HEIGHT / 2);
	// while (floot_index < floot_pos)
	// {
	// 	put_pixel(floot_index, floot_pos, 0xFF0000, map);
	// 	floot_index++;
	// }
	mlx_hook(map->win, MotionNotify, PointerMotionMask, mouse_move, map);
	mlx_loop_hook(map->mlx, draw_loop, map);
	mlx_hook(map->win, KeyPress, KeyPressMask, key_press, map);
	mlx_hook(map->win, KeyRelease, KeyReleaseMask, key_release, map);
	mlx_loop(map->mlx);
	return (0);
}
