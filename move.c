/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:47:25 by slavoie           #+#    #+#             */
/*   Updated: 2022/07/04 14:47:26 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_map *map)
{
	if (!is_exit(map, 30, 0) && !is_wall(map, 30, 0))
	{
		put_image(map, map->floor, map->player.pos.x, map->player.pos.y);
		map->player.pos.x += 30;
		put_image(map, map->player.player, \
		map->player.pos.x, map->player.pos.y);
		if (is_collect(map))
			update_collect(map, map->player.pos);
		map->nb_move++;
		printf("\033[2ANombre de mouvements = %d\n\033[2B", map->nb_move);
	}
}

void	move_left(t_map *map)
{
	if (!is_exit(map, -30, 0) && !is_wall(map, -30, 0))
	{
		put_image(map, map->floor, map->player.pos.x, map->player.pos.y);
		map->player.pos.x -= 30;
		put_image(map, map->player.player, \
		map->player.pos.x, map->player.pos.y);
		if (is_collect(map))
			update_collect(map, map->player.pos);
		map->nb_move++;
		printf("\033[2ANombre de mouvements = %d\n\033[2B", map->nb_move);
	}
}

void	move_down(t_map *map)
{
	if (!is_exit(map, 0, 30) && !is_wall(map, 0, 30))
	{
		put_image(map, map->floor, \
		map->player.pos.x, map->player.pos.y);
		map->player.pos.y += 30;
		put_image(map, map->player.player, \
		map->player.pos.x, map->player.pos.y);
		if (is_collect(map))
			update_collect(map, map->player.pos);
		map->nb_move++;
		printf("\033[2ANombre de mouvements = %d\n\033[2B", map->nb_move);
	}
}

void	move_up(t_map *map)
{
	if (!is_exit(map, 0, -30) && !is_wall(map, 0, -30))
	{
		put_image(map, map->floor, map->player.pos.x, map->player.pos.y);
		map->player.pos.y -= 30;
		put_image(map, map->player.player, \
		map->player.pos.x, map->player.pos.y);
		if (is_collect(map))
			update_collect(map, map->player.pos);
		map->nb_move++;
		printf("\033[2ANombre de mouvements = %d\n\033[2B", map->nb_move);
	}
}
