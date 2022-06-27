#include "so_long.h"


void print_map(t_map *map)
{
	int	l;
	int	c;
	int	x;
	int	y;

	l = 0;
	c = 0;
	x = 0;
	y = 0;

	while(map->map[l] != NULL)
	{
		while(map->map[l][c] != '\n')
		{
			put_image(map, map->floor, x ,y);
			if (map->map[l][c] == '1')
				put_image(map, map->wall, x, y);
			else if (map->map[l][c] == '0')
				put_image(map, map->floor, x, y);
			else if (map->map[l][c] == 'P')
				put_image(map, map->player, x, y);
			else if (map->map[l][c] == 'E')
				put_image(map, map->exit, x, y);
			else if (map->map[l][c] == 'C')
				put_image(map, map->collectible, x, y);
			c++;
			x += 30;
		}
		l++;
		c = 0;
		y += 30;
		x = 0;
	}
}