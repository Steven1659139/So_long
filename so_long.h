#ifndef SO_LONG_H
# define SO_LONG_H

#include "fcntl.h"
#include "Libft/libft.h"
#include "stdio.h"
#include "MinilibX/mlx.h"

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

typedef struct s_map
{
	int	nb_exit;
	int nb_player;
	int nb_collect;
	size_t len_line;
	int	nb_line;
	int	win_size_x;
	int	win_size_y;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	t_image floor;
	t_image ennemi;
	t_image wall;
	t_image player;
	t_image collectible;
	t_image exit;

}				t_map;

#define mem_dec "(y * line_length + x * (bits_per_pixel / 8))"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	put_square(t_image *image, int position_x, int position_y, int hauteur, int largeur, int color);
void	put_circle(t_image *image, int x, int y, int rayon, int color);
void	print_tab(char **tab);
int		check_edge(char *line, t_map *map);
int		check_line(char *line, t_map *map);
void	check_map(char **tab, t_map *map);
char **map(char *argv);
int	tab_length(char **tab);
char	**tab_join(char **tab, char *line);
char	**tab_trunc(char **tab, char *str);
void	set_image(t_map *map, void *mlx);
void	put_image(t_map *map, t_image image, int x, int y);
void print_map(t_map *map);

int	print_keycode(int keycode);
int keycode_event(int keycode, t_map *map);

#endif