#include "so_long.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->adresse + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}