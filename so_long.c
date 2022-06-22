#include "so_long.h"

void	print_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		printf("%s", tab[i]);
}

int	check_edge(char *line)
{
	while (*line)
	{
		if (*line != '1')
			return (0);
		line++;
	}
	return (1);
}

int	check_line(char *line, t_map *map)
{
	if (*line != '1')
		return (0);
	line++;
	while (*line)
	{
		if (*line != '0' || *line != '1' || *line != 'E' || *line != 'C' || *line != 'P')
			return (0);
		if (*line == 'E')
			map->nb_exit++;
		if (*line == 'C')
			map->nb_collect++;
		if (*line == 'P')
			map->nb_player++;
		line++;
	}
	return (1);
}

char **map(char *argv)
{
	int map;
	char	**tab;
	int		i;

	map = open(argv, O_RDONLY, 0777);
	i = -1;
	tab = malloc(6 * sizeof(char *));
	while (tab[i++])
	{
		tab[i] = get_next_line(map);
	}
	return (tab);
}



int main(int argc, char **argv)
{

	char **tab;


	tab = NULL;


	if (argc)
	{
		tab = map(argv[1]);
		print_tab(tab);
	}
		

// 	void	*mlx;
// 	void	*mlx_win;
// 	t_image	img;



// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "So_long");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.adresse = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	//put_square(&img, 400, 400, 50, 100, 0x00FF0000);
// 	//put_circle(&img, 500, 500, 100, 0x00FF0000);
// 	img.img = mlx_xpm_file_to_image(mlx, "TilesetFloor.xpm", &img.width, &img.height);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
}