/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:46:42 by souaammo          #+#    #+#             */
/*   Updated: 2025/05/26 19:46:44 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_cheh_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	ft_check_map(t_parsing *data, short i, short j, short player)
{
	char	**map;

	map = data->map;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_cheh_is_player(map[i][j]) && map[i][j] != '0'
				&& map[i][j] != '1' && map[i][j] != 'D' && map[i][j] != ' ')
			{
				write(2, "Error\nInvalid character found. Only ", 36);
				write (2, "'1', '0', 'N', 'S', 'E', 'W','D' ", 33);
				ft_print_error(data->game, "and space are allowed.\n");
			}
			if (ft_cheh_is_player(map[i][j]))
				player++;
		}
	}
	if (player != 1)
	{
		write(2, "Error\nThere must be exactly one player starting position ",
			57);
		ft_print_error(data->game, "('N', 'S', 'E', or 'W') in the map.\n");
	}
}

void	ft_check_elements(t_parsing *data, size_t i, size_t j, size_t len)
{
	char	**map;

	map = data->map;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || ft_cheh_is_player(map[i][j]))
			{
				if (i == 0 || j == 0 || i == len - 1 || j == ft_strlen(map[i])
					- 1 || !map[i][j + 1] || map[i][j + 1] == ' ' || map[i][j
					- 1] == ' ' || !map[i + 1][j] || map[i + 1][j] == ' '
					|| map[i - 1][j] == ' ' || ft_strlen(map[i + 1]) < j + 1
					|| ft_strlen(map[i - 1]) < j + 1)
					ft_print_error(data->game,
						"Error\nMap is not closed around (?,?).\n");
			}
		}
	}
	ft_check_map(data, -1, -1, 0);
	ft_check_dor_errors(data, -1, -1);
}
