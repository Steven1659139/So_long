/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:47:16 by slavoie           #+#    #+#             */
/*   Updated: 2022/07/04 14:47:18 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_wall(t_map *map)
{
	t_case	*cel;
	t_case	*next_line;
	int		i;

	map->pos_wall = ft_calloc(map->nb_wall, sizeof(t_pos));
	cel = map->first_cel;
	i = 0;
	while (cel->down)
	{
		next_line = cel->down;
		while (cel->right)
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

	map->pos_collect = ft_calloc( map->nb_collect, sizeof(t_pos) );
	cel = map->first_cel;
	i = 0;
	while (cel->down)
	{
		next_line = cel->down;
		while (cel->right)
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
}

void	set_exit(t_map *map)
{
	t_case	*cel;
	t_case	*next_line;
	int		i;

	map->pos_exit = ft_calloc(map->nb_exit, sizeof(t_pos));
	cel = map->first_cel;
	i = 0;
	while (cel->down)
	{
		next_line = cel->down;
		while (cel->right)
		{
			if (cel->state == 'E')
			{
				map->pos_exit[i] = cel->pos;
				i++;
			}
			cel = cel->right;
		}
		cel = next_line;
	}
}

void	update_collect(t_map *map, t_pos pos, int x, int y)
{
	int		i;

	i = 0;
	while (i < map->nb_collect)
	{
		if (pos.x + x == map->pos_collect[i].x && pos.y + y == map->pos_collect[i].y)
		{
			map->pos_collect[i].x = -1;
			map->pos_collect[i].y = -1;
			map->col_on_map -= 1;
			if (map->col_on_map == 0)
				change_sprite(map);

			return ;
		}
		i++;
	}
}

void	change_sprite(t_map *map)
{
	t_list	*list_sprite;
	t_list	*last;

	list_sprite = ft_lstnew(&map->sprite.ultime_1);
	
	ft_lstadd_back(&list_sprite, ft_lstnew(&map->sprite.ultime_2));
	// ft_lstadd_back(&list_sprite, ft_lstnew(&map->sprite.ultime_3));
	// ft_lstadd_back(&list_sprite, ft_lstnew(&map->sprite.ultime_4));

	last = ft_lstlast(list_sprite);
	last->next = list_sprite;
	ft_lstclear(&map->player.sprite, NULL);
	map->player.sprite = list_sprite;
	map->player.player = map->sprite.ultime_1;
	printf("You become a princess!!!\n");
	return ;




}

void	print_coll_and_move(t_map *map)
{
	char	*str;

	str = ft_itoa(map->nb_move);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->sprite.get_rekt.img, 0, 0);
	mlx_string_put(map->mlx, map->mlx_win, 10, 20, 0XFF00FF, "Moves=");
	mlx_string_put(map->mlx, map->mlx_win, 60, 20, 0XFF00FF, str);
	free(str);
	str = ft_itoa(map->col_on_map);
	mlx_string_put(map->mlx, map->mlx_win, 5, 35, 0XFF00FF, str );
	mlx_string_put(map->mlx, map->mlx_win, 15, 35, 0XFF00FF, "collectibles sur");
	free(str);
	str = ft_itoa(map->nb_collect);
	mlx_string_put(map->mlx, map->mlx_win, 130, 35, 0XFF00FF, str);
	free(str);

}
