#include "so_long.h"

void move_right(t_map *map)
{
	map->player.pos_x++;
	put_image(map, map->floor, map->player.pos_x, map->player.pos_y);
	put_image(map, map->player.player, map->player.pos_x, map->player.pos_y);
}