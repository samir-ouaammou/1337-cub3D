/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:46:25 by souaammo          #+#    #+#             */
/*   Updated: 2025/05/26 19:46:27 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3D.h"

short	ft_count_commas(char *str)
{
	short	count;
	short	i;

	if (!str)
		return (0);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

void	ft_check_floor_color(t_parsing *data, char *str)
{
	if (data->data->floor_color[0] != -1)
	{
		write (2, "Error\nDuplicate color identifier: ", 34);
		write (2, "F\nEach color (F for floor, C for ceiling) ", 42);
		ft_print_error(data->game, "must be defined only once.\n");
	}
	data->split = ft_split(data->split[1], ',');
	if (!data->split)
		ft_print_error(data->game,
			"Error\nMemory allocation failed (malloc)\n");
	if (ft_count_len(data->split) != 3 || ft_count_commas(str) != 2)
	{
		write (2, "Error\nInvalid RGB format for floor color. ", 42);
		ft_print_error(data->game, "Expected format: F R,G,B\n");
	}
	data->data->floor_color[0] = ft_atoi(data, data->split[0], 0);
	data->data->floor_color[1] = ft_atoi(data, data->split[1], 0);
	data->data->floor_color[2] = ft_atoi(data, data->split[2], 0);
	if (data->data->floor_color[0] == -1
		|| data->data->floor_color[1] == -1
		|| data->data->floor_color[2] == -1)
	{
		write (2, "Error\nFloor color must contain only integers. ", 46);
		ft_print_error(data->game, "Invalid characters detected.\n");
	}
}

void	ft_check_ceiling_color(t_parsing *data, char *str)
{
	if (data->data->ceiling_color[0] != -1)
	{
		write (2, "Error\nDuplicate color identifier: ", 34);
		write (2, "C\nEach color (F for floor, C for ceiling) ", 42);
		ft_print_error(data->game, "must be defined only once.\n");
	}
	data->split = ft_split(data->split[1], ',');
	if (!data->split)
		ft_print_error(data->game,
			"Error\nMemory allocation failed (malloc)\n");
	if (ft_count_len(data->split) != 3 || ft_count_commas(str) != 2)
	{
		write (2, "Error\nInvalid RGB format for Ceiling color. ", 42);
		ft_print_error(data->game, "Expected format: F R,G,B\n");
	}
	data->data->ceiling_color[0] = ft_atoi(data, data->split[0], 0);
	data->data->ceiling_color[1] = ft_atoi(data, data->split[1], 0);
	data->data->ceiling_color[2] = ft_atoi(data, data->split[2], 0);
	if (data->data->ceiling_color[0] == -1
		|| data->data->ceiling_color[1] == -1
		|| data->data->ceiling_color[2] == -1)
	{
		write (2, "Error\nCeiling color must contain only integers. ", 48);
		ft_print_error(data->game, "Invalid characters detected.\n");
	}
}
