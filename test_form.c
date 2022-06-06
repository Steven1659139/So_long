#include "so_long.h"




void	put_square(t_image *image, int position_x, int position_y, int hauteur, int largeur, int color)
{
	int	temp;

	temp = largeur;


	while(hauteur)
	{
		while(largeur)
		{
			my_mlx_pixel_put(image, hauteur + position_x, largeur + position_y, color);
			largeur--;
		}
		hauteur--;
		largeur = temp;
	}






}