#include "so_long.h"

int	print_keycode(int keycode)
{
	printf("%d\n", keycode);
	return (0);
}

int	keycode_event(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->mlx_win);
		exit(0);
	}
	if (keycode == 2)
		move_right(map);
	if (keycode == 0)
		move_left(map);
	if (keycode == 13)
		move_up(map);
	if (keycode == 1)
		move_down(map);
	return (0);
}

int	quit(t_map *map)
{
	if (map)
	{
		mlx_destroy_window(map->mlx, map->mlx_win);
		exit(0);
	}
	return (0);
}
