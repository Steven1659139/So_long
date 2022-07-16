/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:24:07 by slavoie           #+#    #+#             */
/*   Updated: 2022/07/16 17:24:08 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop_manager(t_map *map)
{
	move_ouachcaca(map);
	print_player_sprite(map);
	return (0);
}

void	image_manager(t_map *map, void *mlx)
{
	image_part1(map, mlx);
	image_part2(map, mlx);
	image_part3(map, mlx);
	create_list_sprite(map);
	init_ouachcaca_image_1(map);
	init_ouachcaca_image_2(map);
	set_case(map);
	print_map(map);
	print_coll_and_move(map);
	print_ouachcaca(map);
	set_wall(map);
	set_collectible(map);
	set_exit(map);
}

void	set_case(t_map	*map)
{
	int		y;
	t_case	*prev_line;

	y = map->nb_line;
	create_first_line(map);
	prev_line = map->first_cel;
	while (y)
	{
		prev_line = create_mid_line(prev_line);
		y--;
	}
	while (prev_line->right)
	{
		prev_line->down = NULL;
		prev_line = prev_line->right;
	}
	update_cel(map);
}

int	collision_manager(t_map *map, t_pos pos, int move_x, int move_y)
{
	if ((!is_wall(map, pos, move_x, move_y) && \
	!is_collect(map, pos, move_x, move_y) && \
	!is_exit(map, map->ouachcaca.pos, move_x, move_y)))
		return (1);
	return (0);
}

void	create_list_sprite(t_map *map)
{	
	t_list	*list_sprite;
	t_list	*last;

	list_sprite = ft_lstnew(&map->sprite.p_sprite_1);
	ft_lstadd_back(&list_sprite, ft_lstnew(&map->sprite.p_sprite_2));
	ft_lstadd_back(&list_sprite, ft_lstnew(&map->sprite.p_sprite_3));
	ft_lstadd_back(&list_sprite, ft_lstnew(&map->sprite.p_sprite_4));
	last = ft_lstlast(list_sprite);
	last->next = list_sprite;
	map->player.sprite = list_sprite;
}
