/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:47:10 by souaammo          #+#    #+#             */
/*   Updated: 2025/05/26 19:47:12 by souaammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_read_map_file(t_parsing *data, short nbr, short bol)
{
	ft_init_parsing(data);
	while (1)
	{
		data->line = get_next_line(data->fd);
		if (!data->line)
			break ;
		data->line = ft_replace_whitespace_with_space(data);
		if (nbr < 6)
			data->line = ft_strtrim(data->line, " ");
		if (data->line[0] == '\n' && bol)
			bol = 42;
		if (data->line[0] != '\n')
		{
			if (bol == 42 && ft_strtrim(data->line, " \t\n\v\f\r"))
			{
				write (2, "Error\nInvalid map: ", 19);
				ft_print_error(data->game, "the map contains errors.\n");
			}
			if (nbr < 6)
				ft_parse_config_line(data);
			else
				bol = ft_map_join(data);
			nbr++;
		}
	}
}

void	ft_parse_config_line(t_parsing *data)
{
	data->line = ft_strtrim(data->line, " \n");
	data->split = ft_split(data->line, ' ');
	if (!data->split)
		ft_print_error(data->game,
			"Error\nMemory allocation failed (malloc)\n");
	if (ft_count_len(data->split) != 2)
		ft_print_map(data->game);
	if (!ft_strcmp(data->split[0], "NO"))
		ft_check_path_north_is_valid(data);
	else if (!ft_strcmp(data->split[0], "SO"))
		ft_check_path_south_is_valid(data);
	else if (!ft_strcmp(data->split[0], "WE"))
		ft_check_path_west_is_valid(data);
	else if (!ft_strcmp(data->split[0], "EA"))
		ft_check_path_east_is_valid(data);
	else if (!ft_strcmp(data->split[0], "F"))
		ft_check_floor_color(data, data->split[1]);
	else if (!ft_strcmp(data->split[0], "C"))
		ft_check_ceiling_color(data, data->split[1]);
	else
		ft_print_map(data->game);
}

char	*ft_replace_whitespace_with_space(t_parsing *data)
{
	short	i;
	char	*res;
	char	*str;

	str = data->line;
	if (!str)
		return (NULL);
	res = ft_malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!res)
		ft_print_error(data->game,
			"Error\nMemory allocation failed (malloc)\n");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
			res[i] = ' ';
		else
			res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

short	ft_count_len(char **strs)
{
	short	i;

	if (!strs)
		return (0);
	i = 0;
	while (strs[i])
		i++;
	return (i);
}

int	ft_map_join(t_parsing *data)
{
	data->tmp = ft_strjoin(data->str, data->line);
	if (!data->tmp)
		ft_print_error(data->game,
			"Error\nMemory allocation failed (malloc)\n");
	data->str = data->tmp;
	return (1);
}
