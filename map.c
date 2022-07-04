/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:51:24 by slavoie           #+#    #+#             */
/*   Updated: 2022/07/04 15:51:25 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			x += 30;
		}
		x = 0;
		y += 30;
		cel = next_line;
	}
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

void	create_first_line(t_map *map)
{
	int		x;
	t_case	*cel;

	cel = malloc(sizeof(t_case));
	cel->left = NULL;
	map->first_cel = cel;
	x = map->len_line - 1;
	while (x)
	{
		cel->up = NULL;
		add_cel(cel);
		x--;
		cel = cel->right;
	}
	cel->right = NULL;
	cel = map->first_cel;
}

t_case	*create_mid_line(t_case *prev_line)
{
	t_case	*new_line;
	t_case	*temp;

	new_line = malloc(sizeof(t_case));
	new_line->left = NULL;
	temp = new_line;
	while (prev_line->right)
	{
		add_cel(new_line);
		prev_line->down = new_line;
		new_line->up = prev_line;
		new_line = new_line->right;
		prev_line = prev_line->right;
	}
	new_line->right = NULL;
	prev_line->down = new_line;
	new_line->up = prev_line;
	return (temp);
}

char	**set_map(char *argv)
{
	int		map;
	char	**tab;
	char	*line;
	int		i;

	map = open(argv, O_RDONLY, 0777);
	if (map == -1)
		yo_its_wrong("Erreur lors de la lecture du fichier.");
	i = 0;
	tab = NULL;
	line = get_next_line(map);
	tab = tab_join(tab, line);
	while (line)
	{
		line = get_next_line(map);
		tab = tab_join(tab, line);
		if (!ft_strchr(tab[i], '\n'))
			tab[i] = ft_strjoin(tab[i], "\n");
		i++;
	}
	tab = tab_trunc(tab, "\n");
	return (tab);
}
