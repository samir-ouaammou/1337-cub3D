#include "../../includes/cub3D.h"

void	ft_init_map_config(t_map_config *data)
{
	data->mlx = NULL;
	data->no_img = NULL;
	data->so_img = NULL;
	data->we_img = NULL;
	data->ea_img = NULL;
	data->map = NULL;
	data->floor_color[0] = -1;
	data->floor_color[1] = -1;
	data->floor_color[2] = -1;
	data->ceiling_color[0] = -1;
	data->ceiling_color[1] = -1;
	data->ceiling_color[2] = -1;
	// data->map_width = 0;
	data->map_height = 0;
	data->player_x = -1;
	data->player_y = -1;
}

void	ft_init_parsing(t_parsing *data)
{
	data->line = NULL;
	data->split = NULL;
	data->tmp = NULL;
	data->str = NULL;
	data->map = NULL;
}

void	ft_print_map(void)
{
	write (2, "Error\nInvalid map format — please ensure the map is ", 54);
	write (2, "properly enclosed and contains valid characters only.\n", 54);
	write (2, "MAP FOR EXMPLE:\n", 16);
	write (2, "NO ./textures/path_to_the_north_texture.xpm\n", 44);
	write (2, "SO ./textures/path_to_the_south_texture.xpm\n", 44);
	write (2, "EA ./textures/path_to_the_east_texture.xpm\n", 43);
	write (2, "WE ./textures/path_to_the_west_texture.xpm\n\n", 44);
	write (2, "F 220,100,0\nC 225,30,0\n\n", 24);
	write (2, "111111111111111\n10000D000001001\n", 32);
	write (2, "1N1101000101001\n111111111111111\n", 32);
	ft_exit(-1);
}

void	ft_print_error(char *str)
{
	while (*str)
		write(2, str++, 1);
	ft_exit(-1);
}

t_map_config	*ft_parsing_map_file(t_map_config *map, char *filename)
{
	t_parsing	data;
	short		len;

	ft_init_parsing(&data);
	data.data = map;
	data.str = ft_strrchr(filename, '/');
	if (data.str && data.str[0] == '/' && data.str[1] && data.str[1] == '.')
		filename = &data.str[1];
	len = ft_strlen(filename);
	if ((len < 5) || (ft_strcmp(&filename[len - 4], ".cub") != 0))
	{
		write(2, "Error\nInvalid map file name. ", 29);
		ft_print_error("Please use a valid file, like map.cub\n");
	}
	data.fd = open(filename, O_RDONLY);
	if (data.fd == -1)
		ft_print_error("Error\nError opening file map\n");
	ft_read_map_file(&data, 0, 0);
	if (!data.str || !data.str[0])
		ft_print_error("Error\nMap file is empty.\n");
	data.map = ft_split(data.str, '\n');
	ft_check_elements(data.map, -1, -1, ft_count_len(data.map));
	ft_player_location_and_map_size(&data, data.map);
	return (data.data);
}
