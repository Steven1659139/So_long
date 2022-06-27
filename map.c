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
			{
				put_image(map, map->player.player, x, y);
				map->player.pos_x = x;
				map->player.pos_y = y;
			}
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

// t_case **set_case(t_map *map)
// {
// 	int	l;
// 	int	c;
// 	int	x;
// 	int	y;
// 	t_case	cel;

// 	l = 0;
// 	c = 0;
// 	x = 0;
// 	y = 0;

// 	cel = malloc(sizeof(t_case));
// 	map->first_cel = &cel;
// 	while(map->map[l] != NULL)
// 	{
// 		while(map->map[l][c] != '\n')
// 		{
			
			
			
			
// 			c++;
// 			x += 30;
// 		}
// 		l++;
// 		c = 0;
// 		y += 30;
// 		x = 0;
// 	}

// }

void	create_cel(t_map *map)
{
	int	x;
	int	y;
	t_case	*cel;
	t_case	*temp;

	x = ft_strlen(map->map[0]) - 1;
	y = tab_length(map->map);

	while (x)
	{
		cel = malloc(sizeof(t_case));
		temp = cel;
		cel = cel->right;
		x--;
	}





}

void	add_cel(t_case *new_cel, t_case	*prev_cel)
{
	prev_cel->right = new_cel;
	new_cel->left = prev_cel;
}