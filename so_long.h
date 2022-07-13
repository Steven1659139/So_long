/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:22:14 by slavoie           #+#    #+#             */
/*   Updated: 2022/07/04 15:22:15 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "Libft/libft.h"
# include <stdio.h>
# include "MinilibX/mlx.h"
# include <math.h>
# include <time.h>

typedef struct s_image
{
	void	*img;
	void	*adresse;
	int		bits_per_pixel;
	int		line_length;
	int		width;
	int		height;
	int		endian;
	char	*path;
}				t_image;

typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct s_player
{
	t_pos	pos;
	t_image	player;
	t_list	*sprite;
}			t_player;

typedef struct s_ouachcaca
{
	t_pos	pos;
	t_list	*sprite_up;
	t_list	*sprite_down;
	t_list	*sprite_left;
	t_list	*sprite_right;
	t_pos	down;
	t_pos	right;
	t_pos	up;
	t_pos	left;
}			t_ouachcaca;

typedef struct s_case
{
	struct s_case	*right;
	struct s_case	*left;
	struct s_case	*up;
	struct s_case	*down;
	char			state;
	t_pos			pos;
	t_image			image;
}			t_case;

typedef	struct s_sprite
{
	t_image	floor;
	t_image	wall;
	t_image	collectible;
	t_image	exit;
	t_image	get_rekt;

	t_image	p_sprite_1;
	t_image	p_sprite_2;
	t_image	p_sprite_3;
	t_image	p_sprite_4;

	t_image ouach_D1;
	t_image ouach_D2;
	t_image ouach_D3;

	t_image	ouach_U1;
	t_image	ouach_U2;

	t_image	ouach_R1;
	t_image	ouach_R2;

	t_image	ouach_L1;
	t_image	ouach_L2;
}			t_sprite;

typedef struct s_map
{
	int			nb_exit;
	int			nb_player;
	int			nb_collect;
	int			col_on_map;
	int			nb_move;
	t_pos		*pos_wall;
	t_pos		*pos_collect;
	t_pos		*pos_exit;
	size_t		len_line;
	int			nb_line;
	int			nb_wall;
	int			win_size_x;
	int			win_size_y;
	char		**map;
	void		*mlx;
	void		*mlx_win;

	t_image		ennemi;
	t_sprite	sprite;
	t_player	player;
	t_ouachcaca	ouachcaca;
	t_case		*first_cel;
	t_case		*player_cel;

}				t_map;


void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	print_tab(char **tab);
int		check_edge(char *line, t_map *map);
int		check_line(char *line, t_map *map);
void	check_map(t_map *map);
char	**map(char *argv);
int		tab_length(char **tab);
char	**tab_join(char **tab, char *line);
char	**tab_trunc(char **tab, char *str);
void	set_image(t_map *map, void *mlx);
void	put_image(t_map *map, t_image image, int x, int y);
void	print_map(t_map *map);

int		print_keycode(int keycode);
int		keycode_event(int keycode, t_map *map);
void	add_cel(t_case *cel);
void	create_first_line(t_map *map);
t_case	*create_mid_line(t_case *prev_line);
void	set_case(t_map	*map);
void	set_cel_image(t_map *map, t_case *cel);

void	move_right(t_map *map);
void	move_up(t_map *map);
void	move_down(t_map *map);
void	move_left(t_map *map);

void	set_wall(t_map *map);
int		is_wall(t_map *map, t_pos pos, int x, int y);
int		is_collect(t_map *map, t_pos pos, int x, int y);
void	update_collect(t_map *map, t_pos pos, int x, int y);
void	set_collectible(t_map *map);
int		is_exit(t_map *map, t_pos pos, int x, int y);
void	set_exit(t_map *map);
int		quit(t_map *map);
void	set_map(t_map *map, char *argv);
void	update_cel(t_map *map);
void	init_map(t_map *map);
void	clean(t_map *map, char *str, int error);
void	free_map(t_map *map);
void	image_destroyer(t_map *map);
void	print_move(t_map *map);
int			print_frog_over_frog(t_map *map);
void	create_list_sprite(t_map *map);

int	print_player_sprite(t_map *map);
void	print_ouachcaca(t_map *map);
void	ouachcaca_sprite(t_map *map);
void	init_ouachcaca_image(t_map *map);
int		move_ouachcaca(t_map *map);

void ouach_move_up(t_map *map);
void ouach_move_down(t_map *map);
void ouach_move_left(t_map *map);
void ouach_move_right(t_map *map);
int loop_manager(t_map *map);

void ouach_move(t_map *map, int *xy, t_list **sprite, int dis);
int go_ouachcaca(t_map *map, int direction);
void	move_player(t_map *map, int *xy, int dis);

void	print_coll_and_move(t_map *map);


#endif
