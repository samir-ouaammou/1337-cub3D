/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:37:23 by aahaded           #+#    #+#             */
/*   Updated: 2025/05/26 19:37:24 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	t_game	*map;

	if (ac != 2)
	{
		write(2, "Error\nMap not found — please ensure the map is", 48);
		write(2, " correctly defined and follows the required format.\n", 52);
		exit(-1);
	}
	map = ft_malloc(sizeof(t_game));
	if (!map)
		ft_print_error(map, "Error\nMemory allocation failed (malloc)\n");
	ft_memset(map, 0, sizeof(t_game));
	ft_init_game(map);
	map->mlx = NULL;
	map->mlx = mlx_init();
	if (!map->mlx)
		ft_print_error(map, "Error\nmlx_init\n");
	map->player.game = map;
	map = ft_parsing_map_file(map, av[1]);
	map->win = mlx_new_window(map->mlx, 1280, 600, "cub3D");
	ft_put_img(map);
	raycasting(map);
	mlx_loop(map->mlx);
	ft_free_image(map);
	ft_exit(0);
}
