/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_it_is.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:51:11 by slavoie           #+#    #+#             */
/*   Updated: 2022/07/04 15:51:13 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	is_exit(t_map *map,t_pos pos, int move_x, int move_y)
{
	int	i;

	i = 0;
	while (i < map->nb_exit)
	{
		if (pos.x + move_x == map->pos_exit[i].x \
		&& pos.y + move_y == map->pos_exit[i].y)
		{
			if (map->col_on_map == 0 && (map->ouachcaca.pos.x + move_x != map->pos_exit[i].x && map->ouachcaca.pos.y + move_y != map->pos_exit[i].y))
			{
				printf("Your reign begin after %d moves\n", map->nb_move);
				clean(map, NULL, 0);
			}

			return (1);
		}
		i++;
	}
	return (0);
}

int	is_wall(t_map *map, t_pos pos, int move_x, int move_y)
{
	int	i;

	i = 0;
	while (i < map->nb_wall)
	{
		if (pos.x + move_x == map->pos_wall[i].x \
		&& pos.y + move_y == map->pos_wall[i].y)
			return (1);
		i++;
	}
	return (0);
}

int	is_collect(t_map *map, t_pos pos, int move_x, int move_y)
{
	int	i;

	i = 0;
	while (i < map->nb_collect)
	{
		if (pos.x + move_x == map->pos_collect[i].x \
		&& pos.y + move_y == map->pos_collect[i].y)
			return (1);
		i++;
	}
	return (0);
}
