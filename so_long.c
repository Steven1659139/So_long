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




// int	render_next_frame(t_map *map)
// {
// 	int	i;
// 	int x;
// 	int y;
// 	int	color[6];
// 	static int	c;

// 	color[0] = 0XFF0000;
// 	color[1] = 0X0CFF00;
// 	color[2] = 0XFFFB00;
// 	color[3] = 0X002EFF;
// 	color[4] = 0XFF00FB;
// 	color[5] = 0X00FFF0;



// 	i = 0;
// 	x = 0;
// 	y = 0;
// 	c = 0;
	


// 	while (i < 1000)
// 	{
// 		mlx_pixel_put(map->mlx, map->mlx_win, x, y, color[c]);
// 		x++;
// 		y++;
// 		i++;



// 	} 
// 	c++;


	

// 	return (0);




// }

// int	main(void)
// {
// 	t_map	*map;

// 	map = malloc(sizeof(t_map));
// 	map->mlx = mlx_init();
// 	map->mlx_win = mlx_new_window(map->mlx, 1000, 1000, "so_long");
// 	mlx_loop_hook(map->mlx, render_next_frame, map);
// 	mlx_loop(map->mlx);
// }








int	main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof (t_map));
	map->map = NULL;
	init_map(map);
	if (argc == 2)
	{
		if (ft_strncmp(ft_strchr(argv[1], '.'), ".ber", ft_strlen(argv[1])))
			clean_error(map, "Le fichier doit être de type .ber\n");
		//printf("\n\n");
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
		create_list_sprite(map);
		mlx_hook(map->mlx_win, 2, 0, keycode_event, map);
		mlx_loop_hook(map->mlx, print_sprite, map);
		// mlx_hook(map->mlx_win, 3, 0, print_frog_over_frog, map);
		// mlx_key_hook(map->mlx_win, , map);
		mlx_hook(map->mlx_win, 17, 0, quit, map);
		mlx_loop(map->mlx);
	}
	free(map);
}
