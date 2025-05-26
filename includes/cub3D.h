/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:35:35 by aahaded           #+#    #+#             */
/*   Updated: 2025/05/26 19:35:36 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../help/GarbageCollector/malloc.h"
# include "../help/get_next_line/get_next_line.h"
# include "../help/libft/libft.h"
# include <SDL2/SDL.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 1280
# define HEIGHT 600
# define BLOCK 8
# define SPEED_CAMERA 0.09
# define SPEED_PLAYER 0.9
# define DEG2RAD 0.017453292519943295
# define FOV (68.0 * DEG2RAD)
# define BUFFER_SIZE 1
# define ESC_KEY 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define SPACE 32
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define LEFT 65361
# define RIGHT 65363
# define DE 1
# define BUFFER_SIZE 1

typedef struct s_game	t_game;

typedef struct s_index
{
	int					i;
	int					j;
	int					x;
	int					y;
	int					h;
	int					k;
}						t_index;

typedef struct s_image
{
	void				*img;
	void				*addr;
	int					width;
	int					heigth;
	unsigned int		color;
}						t_image;

typedef struct s_parsing
{
	int					fd;
	char				*line;
	char				*tmp;
	char				*str;
	char				**split;
	char				**map;

	double				x;
	double				y;
	bool				key_up;
	bool				key_down;
	bool				key_left;
	bool				key_right;
	bool				left_rotate;
	bool				right_rotate;
	t_game				*data;
}						t_parsing;

typedef struct s_textures
{
	void				*img;

	char				*no_img;
	int					no_width;
	int					no_height;

	char				*so_img;
	int					so_width;
	int					so_height;

	char				*we_img;
	int					we_width;
	int					we_height;

	char				*ea_img;
	int					ea_width;
	int					ea_height;

	void				*door_img;
	int					door_width;
	int					door_height;

	void				*wall_img;
	int					wall_width;
	int					wall_height;
}						t_textures;

typedef struct s_draw_textures
{
	int					side;
	int					screen_x;
	double				start_y;
	int					hit_wall;
	int					hit_door;
	double				end_y;
	double				distance;
	double				start_angle;
	double				wall_height;
	int					color;
	int					texture_x;
	int					texture_y;
	void				*wall_img;
	double				wall_hit;

}						t_draw_textures;

typedef struct s_game
{
	void				*mlx;
	void				*win;
	void				*img;
	char				**map;
	void				*addr;
	int					floor_color[3];
	int					ceiling_color[3];
	int					map_width;
	int					map_height;
	double				player_x;
	double				player_y;

	void				*p_img;
	int					p_img_height;
	int					p_img_width;
	unsigned int		color;

	char				*data_pixel;
	int					bpp;
	int					size_line;
	int					endian;
	void				*img_w1;
	float				ray_salib;
	float				ray_mojab;
	float				dx;
	float				dy;
	float				angle;
	int					img_height;
	int					open_door;
	int					close_door;
	int					x_door;
	int					y_door;
	int					close_kay;
	double				player_angle;
	double				dis_y;
	double				dis_x;
	int					step_x;
	int					step_y;
	int					side;
	int					len;
	int					tmp;
	int					map_x;
	int					map_y;
	double				new_x;
	double				new_y;
	double				b3id_x;
	double				b3id_y;
	double				a9rib_x;
	double				a9rib_y;
	t_image				image;
	t_index				index;
	t_parsing			player;
	t_textures			textures;
	t_draw_textures		draw;
}						t_game;

void					ft_print_map(void);
void					*ft_music(void *arg);
char					*get_next_line(int fd);
void					ft_put_img(t_game *map);
void					ft_print_error(char *str);
short					ft_count_len(char **strs);
void					ft_init_game(t_game *data);
int						ft_map_join(t_parsing *data);
void					ft_draw_textures(t_game *game);
void					ft_init_parsing(t_parsing *data);
void					ft_parse_config_line(t_parsing *data);
char					*ft_replace_whitespace_with_space(char *str);
void					ft_check_floor_color(t_parsing *data, char *str);
void					ft_check_ceiling_color(t_parsing *data, char *str);
void					ft_check_dor_errors(char **map, size_t i, size_t j);
t_game					*ft_parsing_map_file(t_game *map, char *filename);
void					ft_read_map_file(t_parsing *data, short nbr, short bol);
void					ft_player_location_and_map_size(t_parsing *data,
							char **str);
void					ft_check_path_north_is_valid(t_parsing *data);
void					ft_check_path_south_is_valid(t_parsing *data);
void					ft_check_path_west_is_valid(t_parsing *data);
void					ft_check_path_east_is_valid(t_parsing *data);
void					ft_check_elements(char **map, size_t i, size_t j,
							size_t len);
void					ft_put_img_to_img(t_game *game, int x_offset,
							int y_offset, int end);

int						close_window(t_game *game);
void					init(t_game *g);
int						draw_map(t_game *g);
int						draw_map(t_game *g);
int						mo_player(t_game *g);
int						color_c(t_game *game);
int						color_f(t_game *game);
void					init_player(t_game *g);
int						draw_loop(t_game *game);
int						raycasting(t_game *map);
void					ft_free_image(t_game *game);
void					clear_image(t_game *game);
void					cast_single_ray(t_game *game);
void					ft_free_image(t_game *game);
void					draw_sky_and_floor(t_game *game);
int						key_press(int keycode, t_game *g);
void					initialize_ray_steps(t_game *game);
int						is_looking_at_door(t_game *g, int c);
int						key_release(int keycode, t_game *g);
void					handle_key_press(t_game *g, int keycode);
int						get_pixel_color(t_game *game, void *img, int x, int y);
void					put_pixel(int x, int y, int color, t_game *g);
void					draw_tile(t_game *g, int x, int y, int color);
void					mo_player_u(t_game *g, double cos_angle,
							double sin_angle);

#endif
