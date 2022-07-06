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
			x += 70;
		}
		x = 0;
		y += 70;
		cel = next_line;
	}
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->get_rekt.img, 0, 0);
	mlx_string_put(map->mlx, map->mlx_win, 10, 0, 0XFF0022, "Move=0");
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

void	set_map(t_map *map, char *argv)
{
	int		fd;

	char	*line;
	int		i;
	char	*temp;

	fd = open(argv, O_RDONLY, 0777);
	if (fd == -1)
		clean_error(map, "Erreur lors de la lecture du fichier.\n");
	i = 0;
	map->map = NULL;
	line = get_next_line(fd);
	map->map = tab_join(map->map, line);
	// printf("%s",map->map[i]);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
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
	close(fd);
	map->map = tab_trunc(map->map, "\n");
}
