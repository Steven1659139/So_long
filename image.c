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

void	put_image(t_map *map, t_image image, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->floor.img, x, y);
	mlx_put_image_to_window(map->mlx, map->mlx_win, image.img, x, y);
}

void	image_part1(t_map *map, void *mlx)
{
	map->floor.path = "TilesetFloor_70.xpm";
	map->exit.path = "exit.xpm";
	map->wall.path = "wall_70.xpm";
	map->collectible.path = "flower_70.xpm";
	map->player.player.path = "frog_2_70.xpm";
	map->floor.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->wall.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->collectible.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->player.player.img = \
	mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->exit.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	// map->floor.adresse = mlx_get_data_addr(map->floor.img, \
	// &map->floor.bits_per_pixel, &map->floor.line_length, &map->floor.endian);
	// map->wall.adresse = mlx_get_data_addr(map->wall.img, \
	// &map->wall.bits_per_pixel, &map->wall.line_length, &map->wall.endian);
	// map->exit.adresse = mlx_get_data_addr(map->exit.img, \
	// &map->exit.bits_per_pixel, &map->exit.line_length, &map->exit.endian);
	// map->collectible.adresse = mlx_get_data_addr(map->collectible.img, \
	// &map->collectible.bits_per_pixel, &map->collectible.line_length, \
	// &map->collectible.endian);
}

void	image_part2(t_map *map, void *mlx)
{
	// map->player.player.adresse = mlx_get_data_addr(map->player.player.img, \
	// &map->player.player.bits_per_pixel, \
	// &map->player.player.line_length, &map->player.player.endian);
	map->floor.img = mlx_xpm_file_to_image(mlx, \
	map->floor.path, &map->floor.width, &map->floor.height);
	map->wall.img = mlx_xpm_file_to_image(mlx, map->wall.path, \
	&map->wall.width, &map->wall.height);
	map->exit.img = mlx_xpm_file_to_image(mlx, map->exit.path, \
	&map->exit.width, &map->exit.height);
	map->collectible.img = mlx_xpm_file_to_image(mlx, map->collectible.path, \
	&map->collectible.width, &map->collectible.height);
	map->player.player.img = mlx_xpm_file_to_image(mlx, \
	map->player.player.path, &map->player.player.width, \
	&map->player.player.height);
}

void	set_image(t_map *map, void *mlx)
{
	image_part1(map, mlx);
	image_part2(map, mlx);
}

void	set_cel_image(t_map *map, t_case *cel)
{
	if (cel->state == '1')
	{
		cel->image = map->wall;
		map->nb_wall++;
	}
	else if (cel->state == '0')
		cel->image = map->floor;
	else if (cel->state == 'C')
		cel->image = map->collectible;
	else if (cel->state == 'P')
	{
		cel->image = map->player.player;
		map->player.pos = cel->pos;
	}
	else if (cel->state == 'E')
		cel->image = map->exit;
}
