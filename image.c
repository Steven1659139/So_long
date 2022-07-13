/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:46:39 by slavoie           #+#    #+#             */
/*   Updated: 2022/07/04 14:46:41 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_map *map, t_image image, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->sprite.floor.img, x, y);
	mlx_put_image_to_window(map->mlx, map->mlx_win, image.img, x, y);
}

void	init_ouachcaca_image(t_map *map)
{
	map->ouachcaca.sprite_down.path = "sprite/ouachcaca/down/ouachcaca_down_1.xpm";
	// map->sprite.ouach_D2.path = "sprite/ouachcaca/down/ouachcaca_down_2.xpm";
	// map->sprite.ouach_D3.path = "sprite/ouachcaca/down/ouachcaca_down_3.xpm";

	map->ouachcaca.sprite_up.path = "sprite/ouachcaca/up/ouachcaca_up_1.xpm";
	// map->sprite.ouach_U2.path = "sprite/ouachcaca/up/ouachcaca_up_2.xpm";

	map->ouachcaca.sprite_right.path = "sprite/ouachcaca/right/ouachcaca_droite_1.xpm";
	// map->sprite.ouach_R2.path = "sprite/ouachcaca/right/ouachcaca_droite_2.xpm";

	map->ouachcaca.sprite_left.path = "sprite/ouachcaca/left/ouachcaca_gauche_1.xpm";
	// map->sprite.ouach_L2.path = "sprite/ouachcaca/left/ouachcaca_gauche_2.xpm";

	map->ouachcaca.sprite_down.img = mlx_new_image(map->mlx, map->win_size_x, map->win_size_y);
	// map->sprite.ouach_D2.img = mlx_new_image(map->mlx, map->win_size_x, map->win_size_y);
	// map->sprite.ouach_D3.img = mlx_new_image(map->mlx, map->win_size_x, map->win_size_y);

	map->ouachcaca.sprite_up.img = mlx_new_image(map->mlx, map->win_size_x, map->win_size_y);
	// map->sprite.ouach_U2.img = mlx_new_image(map->mlx, map->win_size_x, map->win_size_y);

	map->ouachcaca.sprite_right.img = mlx_new_image(map->mlx, map->win_size_x, map->win_size_y);
	// map->sprite.ouach_R2.img = mlx_new_image(map->mlx, map->win_size_x, map->win_size_y);

	map->ouachcaca.sprite_left.img = mlx_new_image(map->mlx, map->win_size_x, map->win_size_y);
	// map->sprite.ouach_L2.img = mlx_new_image(map->mlx, map->win_size_x, map->win_size_y);

	map->ouachcaca.sprite_down.img = mlx_xpm_file_to_image(map->mlx, map->ouachcaca.sprite_down.path, &map->ouachcaca.sprite_down.width, &map->ouachcaca.sprite_down.height);
	// map->sprite.ouach_D2.img = mlx_xpm_file_to_image(map->mlx, map->sprite.ouach_D2.path, &map->sprite.ouach_D2.width, &map->sprite.ouach_D2.height);
	// map->sprite.ouach_D3.img = mlx_xpm_file_to_image(map->mlx, map->sprite.ouach_D3.path, &map->sprite.ouach_D3.width, &map->sprite.ouach_D3.height);

	map->ouachcaca.sprite_up.img = mlx_xpm_file_to_image(map->mlx, map->ouachcaca.sprite_up.path, &map->ouachcaca.sprite_up.width, &map->ouachcaca.sprite_up.height);
	// map->sprite.ouach_U2.img = mlx_xpm_file_to_image(map->mlx, map->sprite.ouach_U2.path, &map->sprite.ouach_U2.width, &map->sprite.ouach_U2.height);

	map->ouachcaca.sprite_right.img = mlx_xpm_file_to_image(map->mlx, map->ouachcaca.sprite_right.path, &map->ouachcaca.sprite_right.width, &map->ouachcaca.sprite_right.height);
	// map->sprite.ouach_R2.img = mlx_xpm_file_to_image(map->mlx, map->sprite.ouach_R2.path, &map->sprite.ouach_R2.width, &map->sprite.ouach_R2.height);

	map->ouachcaca.sprite_left.img = mlx_xpm_file_to_image(map->mlx, map->ouachcaca.sprite_left.path, &map->ouachcaca.sprite_left.width, &map->ouachcaca.sprite_left.height);
	// map->sprite.ouach_L2.img = mlx_xpm_file_to_image(map->mlx, map->sprite.ouach_L2.path, &map->sprite.ouach_L2.width, &map->sprite.ouach_L2.height);

	


}




void	image_part1(t_map *map, void *mlx)
{
	map->sprite.floor.path = "sprite/floor.xpm";
	map->sprite.exit.path = "sprite/exit.xpm";
	map->sprite.wall.path = "sprite/wall.xpm";
	map->sprite.collectible.path = "sprite/flower_70.xpm";
	map->player.player.path = "sprite/player/steven_1.xpm";
	map->sprite.get_rekt.path = "sprite/get_rekt.xpm";
	map->sprite.p_sprite_1.path = "sprite/player/steven_1.xpm";
	map->sprite.p_sprite_2.path = "sprite/player/steven_2.xpm";
	map->sprite.p_sprite_3.path = "sprite/player/steven_3.xpm";
	map->sprite.p_sprite_4.path = "sprite/player/steven_4.xpm";

	map->sprite.ultime_1.path = "sprite/player/ultime_1.xpm";
	map->sprite.ultime_2.path = "sprite/player/ultime_2.xpm";
	map->sprite.ultime_3.path = "sprite/player/ultime_3.xpm";
	map->sprite.ultime_4.path = "sprite/player/ultime_4.xpm";
	// map->player.sprite_2.path = "frog_1.xpm";
	
	map->sprite.floor.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.wall.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.collectible.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->player.player.img = \
	mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.exit.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.get_rekt.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);

	map->sprite.p_sprite_1.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.p_sprite_2.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.p_sprite_3.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.p_sprite_4.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);

	map->sprite.ultime_1.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.ultime_2.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.ultime_3.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	map->sprite.ultime_4.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);

	map->sprite.ultime_1.img = mlx_xpm_file_to_image(mlx, map->sprite.ultime_1.path, \
	&map->sprite.ultime_1.width, &map->sprite.ultime_1.height);

	map->sprite.ultime_2.img = mlx_xpm_file_to_image(mlx, map->sprite.ultime_2.path, \
	&map->sprite.ultime_2.width, &map->sprite.ultime_2.height);

	map->sprite.ultime_3.img = mlx_xpm_file_to_image(mlx, map->sprite.ultime_3.path, \
	&map->sprite.ultime_3.width, &map->sprite.ultime_3.height);

	map->sprite.ultime_4.img = mlx_xpm_file_to_image(mlx, map->sprite.ultime_4.path, \
	&map->sprite.ultime_4.width, &map->sprite.ultime_4.height);
	

	// map->player.sprite_2.img = mlx_new_image(mlx, map->win_size_x, map->win_size_y);
	// map->sprite.floor.adresse = mlx_get_data_addr(map->sprite.floor.img, \
	// &map->sprite.floor.bits_per_pixel, &map->sprite.floor.line_length, &map->sprite.floor.endian);
	// map->sprite.wall.adresse = mlx_get_data_addr(map->sprite.wall.img, \
	// &map->sprite.wall.bits_per_pixel, &map->sprite.wall.line_length, &map->sprite.wall.endian);
	// map->sprite.exit.adresse = mlx_get_data_addr(map->sprite.exit.img, \
	// &map->sprite.exit.bits_per_pixel, &map->sprite.exit.line_length, &map->sprite.exit.endian);
	// map->sprite.collectible.adresse = mlx_get_data_addr(map->sprite.collectible.img, \
	// &map->sprite.collectible.bits_per_pixel, &map->sprite.collectible.line_length, \
	// &map->sprite.collectible.endian);
}

void	image_part2(t_map *map, void *mlx)
{
	// map->player.player.adresse = mlx_get_data_addr(map->player.player.img, \
	// &map->player.player.bits_per_pixel, \
	// &map->player.player.line_length, &map->player.player.endian);
	map->sprite.floor.img = mlx_xpm_file_to_image(mlx, \
	map->sprite.floor.path, &map->sprite.floor.width, &map->sprite.floor.height);
	map->sprite.wall.img = mlx_xpm_file_to_image(mlx, map->sprite.wall.path, \
	&map->sprite.wall.width, &map->sprite.wall.height);
	map->sprite.exit.img = mlx_xpm_file_to_image(mlx, map->sprite.exit.path, \
	&map->sprite.exit.width, &map->sprite.exit.height);
	map->sprite.collectible.img = mlx_xpm_file_to_image(mlx, map->sprite.collectible.path, \
	&map->sprite.collectible.width, &map->sprite.collectible.height);
	map->player.player.img = mlx_xpm_file_to_image(mlx, \
	map->player.player.path, &map->player.player.width, \
	&map->player.player.height);

	map->sprite.get_rekt.img = mlx_xpm_file_to_image(mlx, map->sprite.get_rekt.path, \
	&map->sprite.get_rekt.width, &map->sprite.get_rekt.height);

	map->sprite.p_sprite_1.img = mlx_xpm_file_to_image(mlx, map->sprite.p_sprite_1.path, \
	&map->sprite.p_sprite_1.width, &map->sprite.p_sprite_1.height);

	map->sprite.p_sprite_2.img = mlx_xpm_file_to_image(mlx, map->sprite.p_sprite_2.path, \
	&map->sprite.p_sprite_2.width, &map->sprite.p_sprite_2.height);

	map->sprite.p_sprite_3.img = mlx_xpm_file_to_image(mlx, map->sprite.p_sprite_3.path, \
	&map->sprite.p_sprite_3.width, &map->sprite.p_sprite_3.height);

	map->sprite.p_sprite_4.img = mlx_xpm_file_to_image(mlx, map->sprite.p_sprite_4.path, \
	&map->sprite.p_sprite_4.width, &map->sprite.p_sprite_4.height);	

	// map->player.sprite_2.img = mlx_xpm_file_to_image(mlx, \
	// map->player.sprite_2.path, &map->player.sprite_2.width, \
	// &map->player.sprite_2.height);

}

void	set_image(t_map *map, void *mlx)
{
	image_part1(map, mlx);
	image_part2(map, mlx);
	create_list_sprite(map);
	init_ouachcaca_image(map);
	// ouachcaca_sprite(map);
}

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

// int	print_frog_over_frog(t_map *map)
// {
// 	put_image(map, map->player.sprite_2, map->player.pos.x, map->player.pos.y);

// 	return (0);





// }

int	print_player_sprite(t_map *map)
{

	static int i = 10;


	put_image(map, *(t_image *)map->player.sprite->content, map->player.pos.x, map->player.pos.y);
	if (i-- <= 0)
	{
		map->player.sprite = map->player.sprite->next;
		i = 10;
	}
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
	// map->player.sprite = list_sprite->next;
	// map->player.sprite = list_sprite->next;
	// map->player.sprite = list_sprite->next;
	// map->player.sprite = list_sprite->next;



	// put_image(map, *(t_image *)map->player.sprite->next->next->next->next->content, 10, 10);



}

// void	ouachcaca_sprite(t_map *map)
// {
// 	t_list	*list_sprite_down;
// 	t_list	*list_sprite_left;
// 	t_list	*list_sprite_right;
// 	t_list	*list_sprite_up;
// 	t_list	*last;

// 	list_sprite_down = ft_lstnew(&map->ouachcaca.sprite_down);
	
// 	ft_lstadd_back(&list_sprite_down, ft_lstnew(&map->sprite.ouach_D2));
// 	ft_lstadd_back(&list_sprite_down, ft_lstnew(&map->sprite.ouach_D3));
// 	map->ouachcaca.sprite_down = list_sprite_down;

// 	list_sprite_up = ft_lstnew(&map->ouachcaca.sprite_up);
// 	ft_lstadd_back(&list_sprite_up, ft_lstnew(&map->sprite.ouach_U2));
// 	map->ouachcaca.sprite_up = list_sprite_up;


// 	list_sprite_left = ft_lstnew(&map->sprite.ouach_L1);
// 	ft_lstadd_back(&list_sprite_left, ft_lstnew(&map->sprite.ouach_L2));
// 	map->ouachcaca.sprite_left = list_sprite_left;


// 	list_sprite_right = ft_lstnew(&map->ouachcaca.sprite_right);
// 	ft_lstadd_back(&list_sprite_right, ft_lstnew(&map->sprite.ouach_R2));
// 	map->ouachcaca.sprite_right = list_sprite_right;

// 	last = ft_lstlast(list_sprite_down);
// 	last->next = list_sprite_down;

// 	last = ft_lstlast(list_sprite_left);
// 	last->next = list_sprite_left;
	

// 	last = ft_lstlast(list_sprite_right);
// 	last->next = list_sprite_right;



// 	last = ft_lstlast(list_sprite_up);
// 	last->next = list_sprite_up;
// }