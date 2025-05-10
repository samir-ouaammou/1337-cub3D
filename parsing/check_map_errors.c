#include "../cub3D.h"

int	ft_cheh_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	ft_check_map(char **map, short i, short j, short player)
{
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_cheh_is_player(map[i][j]) && map[i][j] != '1'
				&& map[i][j] != '0' && map[i][j] != ' '
				&& map[i][j] != 'D')
			{
				write(2, "Error\nInvalid character found. Only ", 36);
				write (2, "'1', '0', 'N', 'S', 'E', 'W','D' ", 33);
				ft_print_error("and space are allowed.\n");
			}
			if (ft_cheh_is_player(map[i][j]))
				player++;
		}
	}
	if (player != 1)
	{
		write(2, "Error\nThere must be exactly one player starting position ",
			57);
		ft_print_error("('N', 'S', 'E', or 'W') in the map.\n");
	}
}

void	ft_check_elements(char **map, size_t i, size_t j, size_t len)
{
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
				{
					printf("Error\nMap is not closed around (?,?).\n");
					ft_exit(-1);
				}
			}
		}
	}
}
