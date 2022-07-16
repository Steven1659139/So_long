/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ouachcaca.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:23:16 by slavoie           #+#    #+#             */
/*   Updated: 2022/07/16 17:23:18 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_ouachcaca(t_map *map)
{
	static int	i = 10;
	static int	direction = 1;
	int			count;
	static int	random_timer = 100;

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

int	go_ouachcaca(t_map *map, int direction)
{
	if (collision_manager(map, map->ouachcaca.pos, -90, 0) && direction == 1)
	{
		ouach_move(map, &map->ouachcaca.pos.x, \
		&map->ouachcaca.sprite_left, -90);
		return (1);
	}
	if (collision_manager(map, map->ouachcaca.pos, 0, 90) && direction == 4)
	{
		ouach_move(map, &map->ouachcaca.pos.y, &map->ouachcaca.sprite_down, 90);
		return (1);
	}
	if (collision_manager(map, map->ouachcaca.pos, 90, 0) && direction == 3)
	{
		ouach_move(map, &map->ouachcaca.pos.x, \
		&map->ouachcaca.sprite_right, 90);
		return (1);
	}
	if (collision_manager(map, map->ouachcaca.pos, 0, -90) && direction == 2)
	{
		ouach_move(map, &map->ouachcaca.pos.y, &map->ouachcaca.sprite_up, -90);
		return (1);
	}
	return (0);
}

void	ouach_move(t_map *map, int *xy, t_image *sprite, int dis)
{
	put_image(map, map->sprite.floor, \
	map->ouachcaca.pos.x, map->ouachcaca.pos.y);
	*xy += dis;
	put_image(map, *sprite, map->ouachcaca.pos.x, map->ouachcaca.pos.y);
	if (map->player.pos.x == map->ouachcaca.pos.x && \
	map->player.pos.y == map->ouachcaca.pos.y)
	{
		printf("Ouachcaca got you after %d moves\n", map->nb_move);
		clean(map, NULL, 0);
	}
}
