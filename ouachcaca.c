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
				put_image(map, *(t_image *)map->ouachcaca.sprite_down->content, map->ouachcaca.pos.x, map->ouachcaca.pos.y);
				return ;
			}
			cel = cel->right;
		}
		cel = next_line;
	}
}

int	move_ouachcaca(t_map *map)
{
	static int i = 10;
	static int	direction = 1;
	int 	count;
	static int random_timer = 100;

	count = 0;
	if (i-- <= 0)
	{
		while (count++ != 4 && !go_ouachcaca(map, direction))
		{
			direction = rand() % 4 + 1;
			if (direction == 5)
				direction = 1;
			else if (direction == 0)
				direction = 4;
		}
		i = 10;
	}
	if (random_timer-- == 0)
	{
		direction = rand() % 4 + 1;
		random_timer = rand() % 100 + 1;
	}
	return (0);
}


int go_ouachcaca(t_map *map, int direction)
{
	if ((!is_wall(map,map->ouachcaca.pos, -90, 0) && !is_collect(map, map->ouachcaca.pos, -90, 0) && !is_exit(map, map->ouachcaca.pos, -90, 0)) && direction == 1)
	{
		ouach_move(map, &map->ouachcaca.pos.x, &map->ouachcaca.sprite_left, -90);
		return (1);
	}

	if ((!is_wall(map,map->ouachcaca.pos, 0, 90) && !is_collect(map, map->ouachcaca.pos, 0, 90) && !is_exit(map, map->ouachcaca.pos, 0, 90))&& direction == 4 )
	{
		ouach_move(map, &map->ouachcaca.pos.y, &map->ouachcaca.sprite_down, 90);
		return (1);
	}

	if ((!is_wall(map, map->ouachcaca.pos,90, 0) && !is_collect(map, map->ouachcaca.pos, 90, 0) && !is_exit(map, map->ouachcaca.pos, 90, 0))&& direction == 3 )
	{
		ouach_move(map, &map->ouachcaca.pos.x, &map->ouachcaca.sprite_right, 90);
		return (1);
	}
	if ((!is_wall(map,map->ouachcaca.pos, 0, -90) && !is_collect(map, map->ouachcaca.pos, 0, -90) && !is_exit(map, map->ouachcaca.pos, 0, -90))&& direction == 2 )
	{
		ouach_move(map, &map->ouachcaca.pos.y, &map->ouachcaca.sprite_up, -90);
		return (1);
	}
	return (0);
}

void ouach_move(t_map *map, int *xy, t_list **sprite, int dis)
{
	put_image(map, map->sprite.floor, map->ouachcaca.pos.x, map->ouachcaca.pos.y);
	*xy += dis;
	put_image(map, *(t_image *)(*sprite)->content, map->ouachcaca.pos.x, map->ouachcaca.pos.y );
	*sprite = (*sprite)->next;
	if (map->player.pos.x == map->ouachcaca.pos.x && map->player.pos.y == map->ouachcaca.pos.y)
	{
		printf("Ouachcaca got you after %d moves\n", map->nb_move);
		clean(map, NULL, 0);
		
	}
}

// void ouach_move_right(t_map *map)
// {
	
	
// 	put_image(map, map->sprite.floor, map->ouachcaca.pos.x, map->ouachcaca.pos.y);
// 	map->ouachcaca.pos.x += 90;
// 	put_image(map, *(t_image *)map->ouachcaca.sprite_right->content, map->ouachcaca.pos.x, map->ouachcaca.pos.y );
// 	map->ouachcaca.sprite_right = map->ouachcaca.sprite_right->next;
// }

// void ouach_move_left(t_map *map)
// {
// 	put_image(map, map->sprite.floor, map->ouachcaca.pos.x, map->ouachcaca.pos.y);
// 	map->ouachcaca.pos.x -= 90;
// 	put_image(map, *(t_image *)map->ouachcaca.sprite_left->content, map->ouachcaca.pos.x, map->ouachcaca.pos.y);
// 	map->ouachcaca.sprite_left = map->ouachcaca.sprite_left->next;
// }
// void ouach_move_up(t_map *map)
// {
// 	put_image(map, map->sprite.floor, map->ouachcaca.pos.x, map->ouachcaca.pos.y);
// 	map->ouachcaca.pos.y += 90;
// 	put_image(map, *(t_image *)map->ouachcaca.sprite_up->content, map->ouachcaca.pos.x, map->ouachcaca.pos.y);
// 	map->ouachcaca.sprite_up = map->ouachcaca.sprite_up->next;
// }
// void ouach_move_down(t_map *map)
// {
// 	put_image(map, map->sprite.floor, map->ouachcaca.pos.x, map->ouachcaca.pos.y);
// 	map->ouachcaca.pos.y -= 90;
// 	put_image(map, *(t_image *)map->ouachcaca.sprite_down->content, map->ouachcaca.pos.x, map->ouachcaca.pos.y);
// 	map->ouachcaca.sprite_down = map->ouachcaca.sprite_down->next;
// }

