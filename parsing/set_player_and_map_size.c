#include "../cub3D.h"

void	ft_player_location_and_map_size(t_parsing *data, char **str)
{
	short	i;
	short	j;

	data->data->map = str;
	data->data->player_y = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == 'N' || str[i][j] == 'S'
				|| str[i][j] == 'E' || str[i][j] == 'W')
			{
				data->data->player_x = i;
				data->data->player_y = j;
			}
		}
		// if (data->data->map_width < j)
			// data->data->map_width = j;
	}
	data->data->map_height = i;
}
