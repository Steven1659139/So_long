# include "so_long.h"

void	set_wall(t_map *map)
{
	t_case	*cel;
	t_case	*next_line;
	int		i;

	map->pos_wall = malloc(sizeof(t_pos) * map->nb_wall);

	cel = map->first_cel;
	i = 0;

	while(cel->down)
	{
		next_line = cel->down;
		while(cel->right)
		{
			if (cel->state == '1')
			{
				map->pos_wall[i] = cel->pos;
				i++;
			}
			cel = cel->right;
		}
		cel = next_line;
	}
}

void	set_collectible(t_map *map)
{
	t_case	*cel;
	t_case	*next_line;
	int		i;

	map->pos_collect = malloc(sizeof(t_pos) * map->nb_collect);

	cel = map->first_cel;
	i = 0;

	while(cel->down)
	{
		next_line = cel->down;
		while(cel->right)
		{
			if (cel->state == 'C')
			{
				map->pos_collect[i] = cel->pos;
				i++;
			}
			cel = cel->right;
		}
		cel = next_line;
	}
	i = 0;

	while(i < map->nb_collect)
	{
		printf("%d- x,y = %d,%d\n", i, map->pos_collect[i].x, map->pos_collect[i].y);
		i++;




	}
}

int	is_wall(t_map *map, int	x, int y)
{
	int	i;

	i = 0;
	while (i < map->nb_wall)
	{
		if (map->player.pos.x + x == map->pos_wall[i].x && map->player.pos.y + y == map->pos_wall[i].y)
			return (1);
		i++;
	}
	return (0);
}

int	is_collect(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->nb_collect)
	{
		if (map->player.pos.x == map->pos_collect[i].x && map->player.pos.y == map->pos_collect[i].y)
			return (1);
		i++;
	}
	return (0);
}

void	update_collect(t_map *map, t_pos pos)
{
	t_case	*cel;
	int		i;

	cel = map->first_cel;
	i = 0;

	while(i < map->nb_collect)
	{
		if (pos.x == map->pos_collect[i].x && pos.y == map->pos_collect[i].y)
		{
			map->pos_collect[i].x = -1;
			map->pos_collect[i].y = -1;
			map->col_on_map -= 1;
			printf("%d restants sur %d\n", map->col_on_map, map->nb_collect);
			return ;
		}
		i++;
	}
}
