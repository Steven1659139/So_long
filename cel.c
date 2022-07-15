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

void	update_cel(t_map *map)
{
	t_case	*cel;
	t_case	*next_line;
	int		l;
	int		c;

	c = 0;
	l = 0;
	cel = map->first_cel;
	while (map->map[l])
	{
		next_line = cel->down;
		while (map->map[l][c] != '\n')
		{
			cel->state = map->map[l][c];
			set_cel_image(map, cel);
			cel = cel->right;
			c++;
		}
		l++;
		c = 0;
		cel = next_line;
	}
}

void	add_cel(t_case *cel)
{
	t_case	*new_cel;
	static int i = 2;

	new_cel = malloc(sizeof(t_case));
	printf("Cel %d creat\n", i++);
	cel->right = new_cel;
	new_cel->left = cel;
}
