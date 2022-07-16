/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cel.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:51:56 by slavoie           #+#    #+#             */
/*   Updated: 2022/07/04 15:51:58 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_cel_image(t_map *map, t_case *cel)
{
	if (cel->state == '1')
	{
		cel->image = map->sprite.wall;
		map->nb_wall++;
	}
	else if (cel->state == '0')
		cel->image = map->sprite.floor;
	else if (cel->state == 'C')
		cel->image = map->sprite.collectible;
	else if (cel->state == 'P')
	{
		cel->image = map->player.player;
		map->player.pos = cel->pos;
	}
	else if (cel->state == 'E')
		cel->image = map->sprite.exit;
}

void	add_cel(t_case *cel)
{
	t_case	*new_cel;

	new_cel = ft_calloc(1, sizeof(t_case));
	cel->right = new_cel;
	new_cel->left = cel;
}
