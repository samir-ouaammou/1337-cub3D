# ifndef CUB3D_H
# define CUB3D_H

# include "../help/get_next_line/get_next_line.h"
# include "../help/GarbageCollector/malloc.h"
# include "../help/libft/libft.h"
# include <X11/keysym.h>
# include <SDL2/SDL.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <X11/X.h>
# include <math.h>
# include <mlx.h>

# define WIDTH 1280
# define HEIGHT 6 * BLOCK
# define BLOCK 100
# define TL 8
# define SPEED_CAMERA 0.05
# define SPEED_PLAYER 0.7
# define FOV (M_PI * (70.0 / 180.0))
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

typedef struct s_map_config t_map_config;

typedef struct s_parsing
{
	int			    fd;
	char		    *line;
	char		    *tmp;
	char		    *str;
	char		    **split;
	char		    **map;

    double          x;
    double          y;
	bool            key_up;
    bool            key_down;
    bool            key_left;
    bool            key_right;
    bool            left_rotate;
    bool            right_rotate;
    t_map_config    *data;
}			t_parsing;


typedef struct s_textures
{
	void            *wall_img;
	void            *door_img;
	void            *img;
	int             wall_width;
	int             wall_height;
	int             door_width;
	int             door_height;
} t_textures;

typedef struct s_map_config
{
    void            *mlx;
    void            *win;
    void            *img;
    char		    *no_img;
    char		    *so_img;
    char		    *we_img;
    char		    *ea_img;
    int     	    floor_color[3];
    int     	    ceiling_color[3];
    char    	    **map;

    void            *p_img;
    int             p_img_height;
    int             p_img_width;
    unsigned int    color;

	char            *data_pixel;
    int             bpp;
    int             size_line;
    int             endian;
	void	        *img_w1;
	float           ray_salib;
	float           ray_mojab;
	float           dx;
	float           dy;
	float           angle;
    // int				img_width;
	int				img_height;
    int             open_door;
    int             close_door;
    int             x_door;
    int             y_door;
    int             close_kay;
	double	        player_angle;
    // cs_sound_params_t theme_params;
    // cs_sound_params_t *sound_track;
    t_parsing       player;
    // size_t     	m   ap_width;
    size_t     	    map_height;
    double       	player_x;
    double       	player_y;
    t_textures      textures;
}   t_map_config;

void	            ft_print_map(void);
void                *ft_music(void *arg);
char	            *get_next_line(int fd);
void		        ft_print_error(char *str);
short	            ft_count_len(char **strs);
int                 ft_map_join(t_parsing *data);
void                ft_put_img(t_map_config *map);
void	            ft_init_parsing(t_parsing *data);
void                ft_parse_config_line(t_parsing *data);
void                ft_init_map_config(t_map_config *data);
char                *ft_replace_whitespace_with_space(char *str);
void                ft_check_floor_color(t_parsing *data, char *str);
void                ft_check_ceiling_color(t_parsing *data, char *str);
void	            ft_check_dor_errors(char **map, size_t i, size_t j);
t_map_config	    *ft_parsing_map_file(t_map_config *map, char *filename);
void	            ft_read_map_file(t_parsing *data, short nbr, short bol);
void                ft_player_location_and_map_size(t_parsing *data, char **str);
void                ft_check_path_to_the_north_texture_is_valid(t_parsing *data);
void                ft_check_path_to_the_south_texture_is_valid(t_parsing *data);
void                ft_check_path_to_the_west_texture_is_valid(t_parsing *data);
void                ft_check_path_to_the_east_texture_is_valid(t_parsing *data);
void	            ft_check_elements(char **map, size_t i, size_t j, size_t len);
void    ft_put_img_to_img(t_map_config *game, int x_offset, int y_offset, int n);


void                init(t_map_config *g);
int                 draw_map(t_map_config *g);
int                 draw_loop(t_map_config *game);
int                 raycasting(t_map_config *map);
int                 key_press(int keycode, t_map_config *g);
int                 key_release(int keycode, t_map_config *g);

int get_pixel_color(void *img, int x, int y);
void put_pixel(int x, int y, int color, t_map_config *g);
#endif
