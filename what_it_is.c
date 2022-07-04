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

int	is_exit(t_map *map, int x, int y)
{
	int	i;

	i = 0;
	while (i < map->nb_exit)
	{
		if ((map->player.pos.x + x == map->pos_exit[i].x \
		&& map->player.pos.y + y == map->pos_exit[i].y) && map->col_on_map == 0)
			exit(0);
		if (map->player.pos.x + x == map->pos_exit[i].x \
		&& map->player.pos.y + y == map->pos_exit[i].y)
			return (1);
		i++;
	}
	return (0);
}

int	is_wall(t_map *map, int x, int y)
{
	int	i;

	i = 0;
	while (i < map->nb_wall)
	{
		if (map->player.pos.x + x == map->pos_wall[i].x \
		&& map->player.pos.y + y == map->pos_wall[i].y)
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
		if (map->player.pos.x == map->pos_collect[i].x \
		&& map->player.pos.y == map->pos_collect[i].y)
			return (1);
		i++;
	}
	return (0);
}
