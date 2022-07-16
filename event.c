/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:47:04 by slavoie           #+#    #+#             */
/*   Updated: 2022/07/04 14:47:05 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keycode_event(int keycode, t_map *map)
{
	if (keycode == 53)
		clean(map, NULL, 0);
	if (keycode == 2)
		if (!is_exit(map, map->player.pos, 90, 0) && \
		!is_wall(map, map->player.pos, 90, 0))
			move_player(map, &map->player.pos.x, 90);
	if (keycode == 0)
		if (!is_exit(map, map->player.pos, -90, 0) && \
		!is_wall(map, map->player.pos, -90, 0))
			move_player(map, &map->player.pos.x, -90);
	if (keycode == 13)
		if (!is_exit(map, map->player.pos, 0, -90) && \
		!is_wall(map, map->player.pos, 0, -90))
			move_player(map, &map->player.pos.y, -90);
	if (keycode == 1)
		if (!is_exit(map, map->player.pos, 0, 90) && \
		!is_wall(map, map->player.pos, 0, 90))
			move_player(map, &map->player.pos.y, 90);
	return (0);
}

int	quit(t_map *map)
{
	clean(map, NULL, 0);
	return (0);
}
