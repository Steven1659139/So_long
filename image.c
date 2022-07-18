/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:46:39 by slavoie           #+#    #+#             */
/*   Updated: 2022/07/04 14:46:41 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_ouachcaca_image_1(t_map *map)
{
	map->ouachcaca.sprite_down.path = \
	"sprite/ouachcaca/down/ouachcaca_down_1.xpm";
	map->ouachcaca.sprite_up.path = \
	"sprite/ouachcaca/up/ouachcaca_up_1.xpm";
	map->ouachcaca.sprite_right.path = \
	"sprite/ouachcaca/right/ouachcaca_droite_1.xpm";
	map->ouachcaca.sprite_left.path = \
	"sprite/ouachcaca/left/ouachcaca_gauche_1.xpm";
	map->ouachcaca.sprite_down.img = \
	mlx_new_image(map->mlx, \
	map->win_size_x, map->win_size_y);
	map->ouachcaca.sprite_up.img = \
	mlx_new_image(map->mlx, \
	map->win_size_x, map->win_size_y);
	map->ouachcaca.sprite_right.img = \
	mlx_new_image(map->mlx, \
	map->win_size_x, map->win_size_y);
	map->ouachcaca.sprite_left.img = \
	mlx_new_image(map->mlx, \
	map->win_size_x, map->win_size_y);
}

void	init_ouachcaca_image_2(t_map *map)
{
	map->ouachcaca.sprite_down.img = mlx_xpm_file_to_image(map->mlx,
			map->ouachcaca.sprite_down.path, &map->ouachcaca.sprite_down.width, \
			&map->ouachcaca.sprite_down.height);
	map->ouachcaca.sprite_up.img = mlx_xpm_file_to_image \
	(map->mlx, map->ouachcaca.sprite_up.path, \
	&map->ouachcaca.sprite_up.width, &map->ouachcaca.sprite_up.height);
	map->ouachcaca.sprite_right.img = mlx_xpm_file_to_image(map->mlx, \
	map->ouachcaca.sprite_right.path, \
	&map->ouachcaca.sprite_right.width, &map->ouachcaca.sprite_right.height);
	map->ouachcaca.sprite_left.img = mlx_xpm_file_to_image \
		(map->mlx, map->ouachcaca.sprite_left.path, \
		&map->ouachcaca.sprite_left.width, &map->ouachcaca.sprite_left.height);
}

void	image_part1(t_map *map, void *mlx)
{
	map->sprite.floor.path = "sprite/floor.xpm";
	map->sprite.exit.path = "sprite/exit.xpm";
	map->sprite.wall.path = "sprite/wall.xpm";
	map->sprite.collectible.path = "sprite/flower.xpm";
	map->player.player.path = "sprite/player/steven_1.xpm";
	map->sprite.get_rekt.path = "sprite/get_rekt.xpm";
	map->sprite.p_sprite_1.path = "sprite/player/steven_1.xpm";
	map->sprite.p_sprite_2.path = "sprite/player/steven_2.xpm";
	map->sprite.p_sprite_3.path = "sprite/player/steven_3.xpm";
	map->sprite.p_sprite_4.path = "sprite/player/steven_4.xpm";
	map->sprite.ultime_1.path = "sprite/player/ultime_1.xpm";
	map->sprite.ultime_2.path = "sprite/player/ultime_2.xpm";
	map->sprite.floor.img = \
	mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.wall.img = \
	mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.collectible.img = \
	mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->player.player.img = \
	mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.exit.img = \
	mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.get_rekt.img = \
	mlx_new_image(mlx, map->win_size_x, map->win_size_y);
}

void	image_part2(t_map *map, void *mlx)
{
	map->sprite.p_sprite_1.img = \
	mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.p_sprite_2.img = \
	mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.p_sprite_3.img = \
	mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.p_sprite_4.img = \
	mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.ultime_1.img = \
	mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.ultime_2.img = \
	mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.ultime_1.img = mlx_xpm_file_to_image \
	(mlx, map->sprite.ultime_1.path, \
	&map->sprite.ultime_1.width, &map->sprite.ultime_1.height);
	map->sprite.ultime_2.img = mlx_xpm_file_to_image \
	(mlx, map->sprite.ultime_2.path, \
	&map->sprite.ultime_2.width, &map->sprite.ultime_2.height);
	map->sprite.floor.img = mlx_xpm_file_to_image(mlx, \
	map->sprite.floor.path, &map->sprite.floor.width, \
	&map->sprite.floor.height);
	map->sprite.wall.img = mlx_xpm_file_to_image(mlx, map->sprite.wall.path, \
	&map->sprite.wall.width, &map->sprite.wall.height);
}

void	image_part3(t_map *map, void *mlx)
{
	map->sprite.exit.img = mlx_xpm_file_to_image(mlx, map->sprite.exit.path, \
	&map->sprite.exit.width, &map->sprite.exit.height);
	map->sprite.collectible.img = mlx_xpm_file_to_image \
	(mlx, map->sprite.collectible.path, \
	&map->sprite.collectible.width, &map->sprite.collectible.height);
	map->player.player.img = mlx_xpm_file_to_image(mlx, \
	map->player.player.path, &map->player.player.width, \
	&map->player.player.height);
	map->sprite.get_rekt.img = mlx_xpm_file_to_image \
	(mlx, map->sprite.get_rekt.path, \
	&map->sprite.get_rekt.width, &map->sprite.get_rekt.height);
	map->sprite.p_sprite_1.img = mlx_xpm_file_to_image \
	(mlx, map->sprite.p_sprite_1.path, \
	&map->sprite.p_sprite_1.width, &map->sprite.p_sprite_1.height);
	map->sprite.p_sprite_2.img = mlx_xpm_file_to_image \
	(mlx, map->sprite.p_sprite_2.path, \
	&map->sprite.p_sprite_2.width, &map->sprite.p_sprite_2.height);
	map->sprite.p_sprite_3.img = mlx_xpm_file_to_image \
	(mlx, map->sprite.p_sprite_3.path, \
	&map->sprite.p_sprite_3.width, &map->sprite.p_sprite_3.height);
	map->sprite.p_sprite_4.img = mlx_xpm_file_to_image \
	(mlx, map->sprite.p_sprite_4.path, \
	&map->sprite.p_sprite_4.width, \
	&map->sprite.p_sprite_4.height);
}
