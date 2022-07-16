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

void	create_first_line(t_map *map)
{
	int		x;
	t_case	*cel;

	cel = ft_calloc(1, sizeof(t_case));
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

	new_line = ft_calloc(1, sizeof(t_case));
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

void	set_map(t_map *map, char *argv)
{
	char	*line;
	int		i;
	char	*temp;

	map->fd = open(argv, O_RDONLY, 0777);
	if (map->fd == -1)
		clean(map, "Erreur lors de la lecture du fichier.\n", 1);
	i = 0;
	map->map = NULL;
	line = get_next_line(map->fd);
	map->map = tab_join(map->map, line);
	while (line)
	{
		free(line);
		line = get_next_line(map->fd);
		map->map = tab_join(map->map, line);
		if (!ft_strchr(map->map[i], '\n'))
		{
			temp = map->map[i];
			map->map[i] = ft_strjoin(map->map[i], "\n");
			free(temp);
		}
		i++;
	}
	free(line);
}
