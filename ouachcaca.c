# include "so_long.h"

void	print_ouachcaca(t_map *map)
{
	t_case *cel;
	t_case	*next_line;
	
	cel = map->first_cel;
	while (cel->down)
	{
		next_line = cel->down;
		while (cel->right)
		{
			if (cel->state == '0')
			{
				map->ouachcaca.pos = cel->pos;
				put_image(map, map->sprite.ouach_D1, map->ouachcaca.pos.x, map->ouachcaca.pos.y);
				return ;
			}
			cel = cel->right;
		}
		cel = next_line;
	}
}

// void	move_ouachcaca(t_map *map)
// {
// 	t_pos	down;
// 	t_pos	up;
// 	t_pos	left;
// 	t_pos	right;

// 	down.x = 0;
// 	down.y = -90;

// 	up.x = 0;
// 	up.y = 90;

// 	left.x = -90;
// 	left.y = 0;

// 	right.x = 90;
// 	right.y = 0;

// 	if (!is_wall(map, -90, 0) && !is_collect(map))
// 		put_image(map, )





// }