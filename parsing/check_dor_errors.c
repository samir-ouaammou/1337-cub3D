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
				write (2, "Error\nInvalid door 'D' placement — it must ", 45);
				write (2, "be enclosed by walls ('1') on its left ", 39);
				write (2, "and right, and must be placed between valid ", 44);
				ft_print_error ("floor tiles ('0') above and below.\n");
			}
		}
	}
}
