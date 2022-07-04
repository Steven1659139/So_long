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

	map->pos_wall = malloc(sizeof(t_pos) * map->nb_wall);
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

	map->pos_collect = malloc(sizeof(t_pos) * map->nb_collect);
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

	map->pos_exit = malloc(sizeof(t_pos) * map->nb_exit);
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

void	update_collect(t_map *map, t_pos pos)
{
	int		i;

	i = 0;
	while (i < map->nb_collect)
	{
		if (pos.x == map->pos_collect[i].x && pos.y == map->pos_collect[i].y)
		{
			map->pos_collect[i].x = -1;
			map->pos_collect[i].y = -1;
			map->col_on_map -= 1;
			printf("\033[1A%d restants sur %d\n\033[1B", \
			map->col_on_map, map->nb_collect);
			return ;
		}
		i++;
	}
}
