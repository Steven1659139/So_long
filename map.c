#include "so_long.h"


// void print_map(t_map *map)
// {
// 	int	l;
// 	int	c;
// 	int	x;
// 	int	y;

// 	l = 0;
// 	c = 0;
// 	x = 0;
// 	y = 0;

// 	while(map->map[l] != NULL)
// 	{
// 		while(map->map[l][c] != '\n')
// 		{
// 			put_image(map, map->floor, x ,y);
// 			if (map->map[l][c] == '1')
// 				put_image(map, map->wall, x, y);
// 			else if (map->map[l][c] == '0')
// 				put_image(map, map->floor, x, y);
// 			else if (map->map[l][c] == 'P')
// 			{
// 				put_image(map, map->player.player, x, y);
// 				map->player.pos_x = x;
// 				map->player.pos_y = y;
// 			}
// 			else if (map->map[l][c] == 'E')
// 				put_image(map, map->exit, x, y);
// 			else if (map->map[l][c] == 'C')
// 				put_image(map, map->collectible, x, y);
// 			c++;
// 			x += 30;
// 		}
// 		l++;
// 		c = 0;
// 		y += 30;
// 		x = 0;
// 	}
// }

void	print_map(t_map *map)
{
	t_case	*cel;
	t_case	*next_line;
	int		x;
	int		y;

	x = 0;
	y = 0;

	cel = map->first_cel;

	while(cel->down)
	{
		next_line = cel->down;
		while(cel->right)
		{
			put_image(map, cel->image, x, y);
			cel->pos.x = x;
			cel->pos.y = y;
			if (cel->state == 'P')
				map->player.pos = cel->pos;
			//printf("%c", cel->state);
			cel = cel->right;
			x += 30;
		}
		//printf("\n");
		x = 0;
		y += 30;
		cel = next_line;
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
// 	map->cel = &cel;
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

// void	create_cel(t_map *map)
// {
// 	int	x;
// 	int	y;
// 	t_case	*cel;

// 	x = ft_strlen(map->map[0]) - 2;
// 	y = tab_length(map->map);

// 	cel = malloc(sizeof(t_case));
// 	map->cel = cel;
// 	while (x)
// 	{
// 		add_cel(cel);
// 		x--;
// 		cel = cel->right;
// 	}
// 	cel->right = NULL;





// }

void update_cel(t_map *map)
{
	t_case	*cel;
	t_case	*next_line;
	int		l;
	int		c;

	c = 0;
	l = 0;
	cel = map->first_cel;
	while (map->map[l])
	{
		next_line = cel->down;
		while(map->map[l][c] != '\n')
		{
			cel->state = map->map[l][c];
			set_cel_image(map, cel);
			cel = cel->right;
			c++;
		}
		l++;
		c = 0;
		cel = next_line;
	}
}

void	set_case(t_map	*map)
{
	int	y;
	t_case	*prev_line;

	y = map->nb_line;

	create_first_line(map);
	prev_line = map->first_cel;

	while (y)
	{
		//printf("y = %d\n", y);
		prev_line = create_mid_line(prev_line);
		y--;
	}
	while(prev_line->right)
	{
		prev_line->down = NULL;
		prev_line = prev_line->right;
	}

	update_cel(map);
}

void	create_first_line(t_map *map)
{
	int	x;
	t_case	*cel;

	cel = malloc(sizeof(t_case));
	cel->left = NULL;
	map->first_cel = cel;

	x = map->len_line - 1;

	while (x)
	{
		cel->up = NULL;
		add_cel(cel);
		x--;
		cel = cel->right;
	}
	cel->right = NULL;
	cel = map->first_cel;

}

t_case	*create_mid_line(t_case *prev_line)
{
	t_case	*new_line;
	t_case	*temp;
	new_line = malloc(sizeof(t_case));
	new_line->left = NULL;
	temp = new_line;
	while(prev_line->right)
	{
		add_cel(new_line);
		prev_line->down = new_line;
		new_line->up = prev_line;
		new_line = new_line->right;
		prev_line = prev_line->right;
	}
	new_line->right = NULL;
	prev_line->down = new_line;
	new_line->up = prev_line;

	return (temp);
	





}

void	add_cel(t_case *cel)
{
	t_case	*new_cel;

	new_cel = malloc(sizeof(t_case));
	cel->right = new_cel;
	new_cel->left = cel;

}