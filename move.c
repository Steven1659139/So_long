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
	if (!is_exit(map, 70, 0) && !is_wall(map, 70, 0))
	{
		put_image(map, map->floor, map->player.pos.x, map->player.pos.y);
		map->player.pos.x += 70;
		put_image(map, map->player.player, \
		map->player.pos.x, map->player.pos.y);
		if (is_collect(map))
			update_collect(map, map->player.pos);
		map->nb_move++;
		print_move(map);

	}
}

void	move_left(t_map *map)
{
	if (!is_exit(map, -70, 0) && !is_wall(map, -70, 0))
	{
		put_image(map, map->floor, map->player.pos.x, map->player.pos.y);
		map->player.pos.x -= 70;
		put_image(map, map->player.player, \
		map->player.pos.x, map->player.pos.y);
		if (is_collect(map))
			update_collect(map, map->player.pos);
		map->nb_move++;
		print_move(map);

	}
}

void	move_down(t_map *map)
{
	if (!is_exit(map, 0, 70) && !is_wall(map, 0, 70))
	{
		put_image(map, map->floor, \
		map->player.pos.x, map->player.pos.y);
		map->player.pos.y += 70;
		put_image(map, map->player.player, \
		map->player.pos.x, map->player.pos.y);
		if (is_collect(map))
			update_collect(map, map->player.pos);
		map->nb_move++;
		print_move(map);

	}
}

void	move_up(t_map *map)
{
	if (!is_exit(map, 0, -70) && !is_wall(map, 0, -70))
	{
		put_image(map, map->floor, map->player.pos.x, map->player.pos.y);
		map->player.pos.y -= 70;
		put_image(map, map->player.player, \
		map->player.pos.x, map->player.pos.y);
		if (is_collect(map))
			update_collect(map, map->player.pos);
		map->nb_move++;
		print_move(map);
	}
}

void	print_move(t_map *map)
{
	char	*str;

	str = ft_itoa(map->nb_move);
	mlx_string_put(map->mlx, map->mlx_win, 50, 10, 0XFF00FF, str);
	free(str);
}