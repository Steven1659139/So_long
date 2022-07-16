/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:47:16 by slavoie           #+#    #+#             */
/*   Updated: 2022/07/04 14:47:18 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_wall(t_map *map)
{
	t_case	*cel;
	t_case	*next_line;
	int		i;

	map->pos_wall = ft_calloc(map->nb_wall, sizeof(t_pos));
	cel = map->first_cel;
	i = 0;
	while (cel->down)
	{
		next_line = cel->down;
		while (cel->right)
		{
			if (cel->state == '1')
			{
				map->pos_wall[i] = cel->pos;
				i++;
			}
			cel = cel->right;
		}
		cel = next_line;
	}
}

void	set_collectible(t_map *map)
{
	t_case	*cel;
	t_case	*next_line;
	int		i;

	map->pos_collect = ft_calloc(map->nb_collect, sizeof(t_pos));
	cel = map->first_cel;
	i = 0;
	while (cel->down)
	{
		next_line = cel->down;
		while (cel->right)
		{
			if (cel->state == 'C')
			{
				map->pos_collect[i] = cel->pos;
				i++;
			}
			cel = cel->right;
		}
		cel = next_line;
	}
}

void	set_exit(t_map *map)
{
	t_case	*cel;
	t_case	*next_line;
	int		i;

	map->pos_exit = ft_calloc(map->nb_exit, sizeof(t_pos));
	cel = map->first_cel;
	i = 0;
	while (cel->down)
	{
		next_line = cel->down;
		while (cel->right)
		{
			if (cel->state == 'E')
			{
				map->pos_exit[i] = cel->pos;
				i++;
			}
			cel = cel->right;
		}
		cel = next_line;
	}
}
