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
	if (!is_exit(map,map->player.pos, 90, 0) && !is_wall(map,map->player.pos ,90, 0))
	{
		put_image(map, map->sprite.floor, map->player.pos.x, map->player.pos.y);
		if (is_collect(map, map->player.pos, 90, 0))
			update_collect(map, map->player.pos, 90, 0);
		map->player.pos.x += 90;
		put_image(map, map->player.player, \
		map->player.pos.x, map->player.pos.y);
		map->nb_move++;
		print_move(map);

	}
}

void	move_left(t_map *map)
{
	if (!is_exit(map,map->player.pos, -90, 0) && !is_wall(map,map->player.pos, -90, 0))
	{
		put_image(map, map->sprite.floor, map->player.pos.x, map->player.pos.y);
		if (is_collect(map, map->player.pos, -90, 0))
			update_collect(map, map->player.pos, -90, 0);
		map->player.pos.x -= 90;
		put_image(map, map->player.player, \
		map->player.pos.x, map->player.pos.y);
		map->nb_move++;
		print_move(map);

	}
}

void	move_down(t_map *map)
{
	if (!is_exit(map,map->player.pos, 0, 90) && !is_wall(map,map->player.pos, 0, 90))
	{
		put_image(map, map->sprite.floor, \
		map->player.pos.x, map->player.pos.y);
		if (is_collect(map, map->player.pos, 0, 90))
			update_collect(map, map->player.pos, 0, 90);
		map->player.pos.y += 90;
		put_image(map, map->player.player, \
		map->player.pos.x, map->player.pos.y);
		map->nb_move++;
		print_move(map);

	}
}

void	move_up(t_map *map)
{
	if (!is_exit(map,map->player.pos, 0, -90) && !is_wall(map,map->player.pos, 0, -90))
	{
		put_image(map, map->sprite.floor, map->player.pos.x, map->player.pos.y);
		if (is_collect(map, map->player.pos, 0, -90))
			update_collect(map, map->player.pos, 0, -90);
		map->player.pos.y -= 90;
		put_image(map, map->player.player, \
		map->player.pos.x, map->player.pos.y);
		map->nb_move++;
		print_move(map);
	}
}

void	print_move(t_map *map)
{
	char	*str;

	str = ft_itoa(map->nb_move);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->sprite.get_rekt.img, 0, 0);
	mlx_string_put(map->mlx, map->mlx_win, 10, 20, 0XFF00FF, "Moves=");
	mlx_string_put(map->mlx, map->mlx_win, 60, 20, 0XFF00FF, str);
	free(str);
}