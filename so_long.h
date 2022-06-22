#ifndef SO_LONG_H
# define SO_LONG_H

#include "fcntl.h"
#include "Libft/libft.h"
#include "stdio.h"
#include "mlx.h"

typedef struct s_image
{
	void	*img;
	void	*adresse;
	int		bits_per_pixel;
	int		line_length;
	int		width;
	int		height;
	int		endian;
}				t_image;

typedef struct s_map
{
	int	nb_exit;
	int nb_player;
	int nb_collect;
}				t_map;

#define mem_dec "(y * line_length + x * (bits_per_pixel / 8))"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	put_square(t_image *image, int position_x, int position_y, int hauteur, int largeur, int color);
void	put_circle(t_image *image, int x, int y, int rayon, int color);

#endif