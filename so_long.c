#include "so_long.h"



void map(char *argv)
{
	int map;
	char	*line;

	map = open(argv, O_RDONLY, 0777);

	line = get_next_line(map);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(map);
	}
}



int main(int argc, char **argv)
{
	
	if (argc)
		map(argv[1]);

	void	*mlx;
	void	*mlx_win;
	t_image	img;



	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "So_long");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.adresse = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	//put_square(&img, 400, 400, 50, 100, 0x00FF0000);
	//put_circle(&img, 500, 500, 100, 0x00FF0000);
	img.img = mlx_xpm_file_to_image(mlx, "TilesetFloor.xpm", &img.width, &img.height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}