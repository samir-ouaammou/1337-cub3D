#include "../cub3D.h"

//void	ft_check_texture_is_valid(t_parsing *data, char *str, int nbr)
//{
//	str = ft_strtrim(str, " \n");
//	data->split = ft_split(str, ' ');
//	if (!data->split)
//		ft_print_error("Error\nMemory allocation failed (malloc)\n");
//	if (nbr == 0)
//		ft_check_path_to_the_north_texture_is_valid(data);
//	else if (nbr == 1)
//		ft_check_path_to_the_south_texture_is_valid(data);
//	else if (nbr == 2)
//		ft_check_path_to_the_west_texture_is_valid(data);
//	else if (nbr == 3)
//		ft_check_path_to_the_east_texture_is_valid(data);
//}

void	ft_check_path_to_the_north_texture_is_valid(t_parsing *data)
{
	int	width;
	int	height;

	if (data->data->no_texture)
	{
		write (2, "Error\nDuplicate texture identifier: ", 36);
		write (2, "NO\nEach texture (NO, SO, WE, EA) ", 33);
		ft_print_error("must be defined only once.\n");
	}
	if (ft_count_len(data->split) != 2 || ft_strcmp(data->split[0], "NO"))
	{
		write (2, "Error\nInvalid north texture path\nExample: ", 42);
		ft_print_error ("NO ./path_to_the_north_texture.xpm\n");
	}
	data->data->no_texture = mlx_xpm_file_to_image(data->data->mlx,
			data->split[1], &width, &height);
	if (!data->data->no_texture)
	{
		write (2, "Error\nFailed to load north texture\nCheck the path: ", 51);
		ft_print_error("NO ./path_to_the_north_texture.xpm\n");
	}
}

void	ft_check_path_to_the_south_texture_is_valid(t_parsing *data)
{
	int	width;
	int	height;

	if (data->data->so_texture)
	{
		write (2, "Error\nDuplicate texture identifier: ", 36);
		write (2, "SO\nEach texture (NO, SO, WE, EA) ", 33);
		ft_print_error("must be defined only once.\n");
	}
	if (ft_count_len(data->split) != 2 || ft_strcmp(data->split[0], "SO"))
	{
		write (2, "Error\nInvalid south texture path\nExample: ", 42);
		ft_print_error ("SO ./path_to_the_south_texture.xpm\n");
	}
	data->data->so_texture = mlx_xpm_file_to_image(data->data->mlx,
			data->split[1], &width, &height);
	if (!data->data->so_texture)
	{
		write (2, "Error\nFailed to load south texture\nCheck the path: ", 51);
		ft_print_error ("SO ./path_to_the_south_texture.xpm\n");
	}
}

void	ft_check_path_to_the_west_texture_is_valid(t_parsing *data)
{
	int	width;
	int	height;

	if (data->data->we_texture)
	{
		write (2, "Error\nDuplicate texture identifier: ", 36);
		write (2, "WE\nEach texture (NO, SO, WE, EA) ", 33);
		ft_print_error("must be defined only once.\n");
	}
	if (ft_count_len(data->split) != 2 || ft_strcmp(data->split[0], "WE"))
	{
		write (2, "Error\nInvalid west texture path\nExample: ", 41);
		ft_print_error ("WE ./path_to_the_west_texture.xpm\n");
	}
	data->data->we_texture = mlx_xpm_file_to_image(data->data->mlx,
			data->split[1], &width, &height);
	if (!data->data->we_texture)
	{
		write (2, "Error\nFailed to load west texture\nCheck the path: ", 50);
		ft_print_error ("WE ./path_to_the_west_texture.xpm\n");
	}
}

void	ft_check_path_to_the_east_texture_is_valid(t_parsing *data)
{
	int	width;
	int	height;

	if (data->data->ea_texture)
	{
		write (2, "Error\nDuplicate texture identifier: ", 36);
		write (2, "EA\nEach texture (NO, SO, WE, EA) ", 33);
		ft_print_error("must be defined only once.\n");
	}
	if (ft_count_len(data->split) != 2 || ft_strcmp(data->split[0], "EA"))
	{
		write (2, "Error\nInvalid east texture path\nExample: ", 41);
		ft_print_error ("EA ./path_to_the_east_texture.xpm\n");
	}
	data->data->ea_texture = mlx_xpm_file_to_image(data->data->mlx,
			data->split[1], &width, &height);
	if (!data->data->ea_texture)
	{
		write (2, "Error\nFailed to load east texture\nCheck the path: ", 50);
		ft_print_error ("EA ./path_to_the_east_texture.xpm\n");
	}
}
