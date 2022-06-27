#include "so_long.h"


int	print_keycode(int keycode)
{
	printf("%d\n", keycode);
	return (0);
}

int keycode_event(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->mlx_win);
		exit(0);
	}

	return (0);
	
}