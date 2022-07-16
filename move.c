/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:47:25 by slavoie           #+#    #+#             */
/*   Updated: 2022/07/16 17:24:22 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_map *map, int *xy, int dis)
{
	put_image(map, map->sprite.floor, map->player.pos.x, map->player.pos.y);
	*xy += dis;
	put_image(map, map->player.player, \
	map->player.pos.x, map->player.pos.y);
	if (is_collect(map, map->player.pos, 0, 0))
		update_collect(map, map->player.pos, 0, 0);
	if (map->player.pos.x == map->ouachcaca.pos.x && \
	map->player.pos.y == map->ouachcaca.pos.y)
	{
		printf("Ouachcaca got you after %d\n", map->nb_move);
		clean(map, NULL, 0);
	}
	map->nb_move++;
	print_coll_and_move(map);
}
