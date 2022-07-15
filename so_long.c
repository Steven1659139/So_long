/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:46:52 by slavoie           #+#    #+#             */
/*   Updated: 2022/07/04 14:46:55 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	tab_length(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**tab_trunc(char **tab, char *str)
{
	int		i;
	char	**new_tab;

	i = 0;
	new_tab = NULL;
	if (!tab || !str)
		return (0);
	
	while (tab[i] && ft_strncmp(tab[i], str, ft_strlen(tab[i])) != 0)
	{
		new_tab = tab_join(new_tab, tab[i]);
		i++;
	}
	
	if (new_tab)
		new_tab[i] = NULL;
	table_flip(tab);
	return (new_tab);
}

char	**tab_join(char **tab, char *line)
{
	int		len;
	char	**new_tab;
	int		i;

	i = 0;
	if (!tab)
	{
		new_tab = malloc(sizeof (char *) * 2);
		new_tab[i++] = ft_strdup(line);
		new_tab[i] = NULL;
		return (new_tab);
	}
	len = tab_length(tab);
	new_tab = malloc ((len + 2) * sizeof(char *));
	while (i < len)
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i++] = ft_strdup(line);
	new_tab[i] = 0;
	table_flip(tab);
	return (new_tab);
}

void	init_map(t_map *map)
{
	map->nb_wall = 0;
	map->nb_move = 0;
	map->nb_player = 0;
	map->nb_collect = 0;
	map->pos_collect = NULL;
	map->pos_exit = NULL;
	map->pos_wall = NULL;
	map->first_cel = NULL;
	map->mlx = NULL;
	map->mlx_win = NULL;
	map->player_cel = NULL;


}








int	main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof (t_map));
	map->map = NULL;
	init_map(map);
	srand(time(0));
	if (argc == 2)
	{
		if (ft_strncmp(ft_strchr(argv[1], '.'), ".ber", ft_strlen(argv[1])))
			clean(map, "Le fichier doit être de type .ber\n", 1);
		set_map(map, argv[1]);
		check_map(map);
		map->col_on_map = map->nb_collect;
		map->win_size_x = (ft_strlen(map->map[0]) * 90) - 90;
		map->win_size_y = (tab_length(map->map) * 90);
		map->mlx = mlx_init();
		map->mlx_win = mlx_new_window(map->mlx, map->win_size_x, \
		map->win_size_y, "So_long");
		set_image(map, map->mlx);
		set_case(map);
		print_map(map);
		set_wall(map);
		set_collectible(map);
		set_exit(map);
		print_ouachcaca(map);
		mlx_hook(map->mlx_win, 2, 0, keycode_event, map);
		mlx_hook(map->mlx_win, 17, 0, quit, map);
		mlx_loop_hook(map->mlx, loop_manager, map);
		mlx_loop(map->mlx);
	}
	free(map);
}
