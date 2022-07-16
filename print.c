/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:22:19 by slavoie           #+#    #+#             */
/*   Updated: 2022/07/16 17:22:20 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_ouachcaca(t_map *map)
{
	t_case	*cel;
	t_case	*next_line;

	cel = map->first_cel;
	while (cel->down)
	{
		next_line = cel->down;
		while (cel->right)
		{
			if (cel->state == '0')
			{
				map->ouachcaca.pos = cel->pos;
				put_image(map, map->ouachcaca.sprite_down, \
				map->ouachcaca.pos.x, map->ouachcaca.pos.y);
				return ;
			}
			cel = cel->right;
		}
		cel = next_line;
	}
}

void	put_image(t_map *map, t_image image, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, \
	map->sprite.floor.img, x, y);
	mlx_put_image_to_window(map->mlx, map->mlx_win, image.img, x, y);
}

int	print_player_sprite(t_map *map)
{
	static int	i = 10;

	put_image(map, *(t_image *)map->player.sprite->content, \
	map->player.pos.x, map->player.pos.y);
	if (i-- <= 0)
	{
		map->player.sprite = map->player.sprite->next;
		i = 10;
	}
	return (0);
}

void	print_map(t_map *map)
{
	t_case	*cel;
	t_case	*next_line;
	int		x;
	int		y;

	x = 0;
	y = 0;
	cel = map->first_cel;
	while (cel->down)
	{
		next_line = cel->down;
		while (cel->right)
		{
			put_image(map, cel->image, x, y);
			cel->pos.x = x;
			cel->pos.y = y;
			if (cel->state == 'P')
				map->player.pos = cel->pos;
			cel = cel->right;
			x += 90;
		}
		x = 0;
		y += 90;
		cel = next_line;
	}
}
