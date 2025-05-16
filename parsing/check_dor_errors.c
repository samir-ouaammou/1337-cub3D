#include "../cub3D.h"

void	ft_check_dor_errors(char **map, size_t i, size_t j)
{
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((map[i][j] == 'D')
				&& (map[i][j - 1] != '1' || map[i][j + 1] != '1'
				|| ft_strlen(map[i - 1]) < j || ft_strlen(map[i + 1]) < j
				|| map[i - 1][j] != '0' || map[i + 1][j] != '0'))
			{
				write (2, "Error\nInvalid door 'D' placement — 'D' ", 41);
				write (2, "must be enclosed by walls ('1') on its ", 39);
				write (2, "left and right, and there must be no ", 37);
				ft_print_error("empty space or void above or below it.\n");
			}
		}
	}
}
