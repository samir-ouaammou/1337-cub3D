/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:46:53 by souaammo          #+#    #+#             */
/*   Updated: 2025/05/26 19:46:55 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3D.h"

void	ft_check_path_north_is_valid(t_parsing *data)
{
	if (data->data->textures.no_img)
	{
		write (2, "Error\nDuplicate texture identifier: ", 36);
		write (2, "NO\nEach texture (NO, SO, WE, EA) ", 33);
		ft_print_error(data->game, "must be defined only once.\n");
	}
	if (ft_count_len(data->split) != 2 || ft_strcmp(data->split[0], "NO"))
	{
		write (2, "Error\nInvalid north texture path\nExample: ", 42);
		ft_print_error(data->game, "NO ./path_to_the_north_texture.xpm\n");
	}
	data->data->textures.no_img = mlx_xpm_file_to_image(data->data->mlx,
			data->split[1], &data->data->textures.no_width,
			&data->data->textures.no_height);
	if (!data->data->textures.no_img)
	{
		write (2, "Error\nFailed to load north texture\n", 36);
		ft_print_error(data->game, "NO ./path_to_the_north_texture.xpm\n");
	}
}

void	ft_check_path_south_is_valid(t_parsing *data)
{
	if (data->data->textures.so_img)
	{
		write (2, "Error\nDuplicate texture identifier: ", 36);
		write (2, "SO\nEach texture (NO, SO, WE, EA) ", 33);
		ft_print_error(data->game, "must be defined only once.\n");
	}
	if (ft_count_len(data->split) != 2 || ft_strcmp(data->split[0], "SO"))
	{
		write (2, "Error\nInvalid south texture path\nExample: ", 42);
		ft_print_error(data->game, "SO ./path_to_the_south_texture.xpm\n");
	}
	data->data->textures.so_img = mlx_xpm_file_to_image(data->data->mlx,
			data->split[1], &data->data->textures.so_width,
			&data->data->textures.so_height);
	if (!data->data->textures.so_img)
	{
		write (2, "Error\nFailed to load south texture\n", 36);
		ft_print_error(data->game, "SO ./path_to_the_south_texture.xpm\n");
	}
}

void	ft_check_path_west_is_valid(t_parsing *data)
{
	if (data->data->textures.we_img)
	{
		write (2, "Error\nDuplicate texture identifier: ", 36);
		write (2, "WE\nEach texture (NO, SO, WE, EA) ", 33);
		ft_print_error(data->game, "must be defined only once.\n");
	}
	if (ft_count_len(data->split) != 2 || ft_strcmp(data->split[0], "WE"))
	{
		write (2, "Error\nInvalid west texture path\nExample: ", 41);
		ft_print_error(data->game, "WE ./path_to_the_west_texture.xpm\n");
	}
	data->data->textures.we_img = mlx_xpm_file_to_image(data->data->mlx,
			data->split[1], &data->data->textures.we_width,
			&data->data->textures.we_height);
	if (!data->data->textures.we_img)
	{
		write (2, "Error\nFailed to load west texture\n", 34);
		ft_print_error(data->game, "WE ./path_to_the_west_texture.xpm\n");
	}
}

void	ft_check_path_east_is_valid(t_parsing *data)
{
	if (data->data->textures.ea_img)
	{
		write (2, "Error\nDuplicate texture identifier: ", 36);
		write (2, "EA\nEach texture (NO, SO, WE, EA) ", 33);
		ft_print_error(data->game, "must be defined only once.\n");
	}
	if (ft_count_len(data->split) != 2 || ft_strcmp(data->split[0], "EA"))
	{
		write (2, "Error\nInvalid east texture path\nExample: ", 41);
		ft_print_error(data->game, "EA ./path_to_the_east_texture.xpm\n");
	}
	data->data->textures.ea_img = mlx_xpm_file_to_image(data->data->mlx,
			data->split[1], &data->data->textures.ea_width,
			&data->data->textures.ea_height);
	if (!data->data->textures.ea_img)
	{
		write (2, "Error\nFailed to load east texture\n ", 50);
		ft_print_error(data->game, "EA ./path_to_the_east_texture.xpm\n");
	}
}
