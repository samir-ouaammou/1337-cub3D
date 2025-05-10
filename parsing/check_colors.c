#include "../cub3D.h"

//void	ft_check_colors_is_valid(t_parsing *data, char *str, int nbr)
//{
//	str = ft_strtrim(str, " \n");
//	data->split = ft_split(str, ' ');
//	if (!data->split)
//		ft_print_error("Error\nMemory allocation failed (malloc)\n");
//	if (nbr == 4)
//		ft_check_floor_color(data);
//	else if (nbr == 5)
//		ft_check_ceiling_color(data);
//}

void	ft_check_floor_color(t_parsing *data)
{
	//if (ft_count_len(data->split) != 2 || ft_strcmp(data->split[0], "F"))
	//{
	//	write (2, "Error\nInvalid floor color format — ", 37);
	//	ft_print_error("Example: F 220,100,0\n");
	//}
	if (data->data->floor_color[0] != -1)
	{
		write (2, "Error\nDuplicate color identifier: ", 34);
		write (2, "F\nEach color (F for floor, C for ceiling) ", 42);
		ft_print_error("must be defined only once.\n");
	}
	data->split = ft_split(data->split[1], ',');
	if (!data->split)
		ft_print_error("Error\nMemory allocation failed (malloc)\n");
	if (ft_count_len(data->split) != 3)
	{
		write (2, "Error\nInvalid floor color format — ", 37);
		ft_print_error("Example: F 220,100,0\n");
	}
	data->data->floor_color[0] = ft_atoi(data->split[0]);
	data->data->floor_color[1] = ft_atoi(data->split[1]);
	data->data->floor_color[2] = ft_atoi(data->split[2]);
	if (data->data->floor_color[0] == -1
		|| data->data->floor_color[1] == -1
		|| data->data->floor_color[2] == -1)
	{
		write (2, "Error\nFloor color must contain only integers. ", 46);
		ft_print_error("Invalid characters detected.\n");
	}
}

void	ft_check_ceiling_color(t_parsing *data)
{
	//if (ft_count_len(data->split) != 2 || ft_strcmp(data->split[0], "C"))
	//{
	//	write (2, "Error\nInvalid ceiling color format — ", 39);
	//	ft_print_error("Example: C 225,30,0\n");
	//}
	if (data->data->ceiling_color[0] != -1)
	{
		write (2, "Error\nDuplicate color identifier: ", 34);
		write (2, "C\nEach color (F for floor, C for ceiling) ", 42);
		ft_print_error("must be defined only once.\n");
	}
	data->split = ft_split(data->split[1], ',');
	if (!data->split)
		ft_print_error("Error\nMemory allocation failed (malloc)\n");
	if (ft_count_len(data->split) != 3)
	{
		write (2, "Error\nInvalid ceiling color format — ", 37);
		ft_print_error("Example: C 225,30,0\n");
	}
	data->data->ceiling_color[0] = ft_atoi(data->split[0]);
	data->data->ceiling_color[1] = ft_atoi(data->split[1]);
	data->data->ceiling_color[2] = ft_atoi(data->split[2]);
	if (data->data->ceiling_color[0] == -1
		|| data->data->ceiling_color[1] == -1
		|| data->data->ceiling_color[2] == -1)
	{
		write (2, "Error\nCeiling color must contain only integers. ", 48);
		ft_print_error("Invalid characters detected.\n");
	}
}
