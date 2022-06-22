#include "so_long.h"

int	tab_length(char **tab)
{
	int	i;

	i = 0;

	while (*tab)
	{
		i++;
		tab++;
	}

	return (i);
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

	return (new_tab);
}


char **map(char *argv)
{
	int		carte;
	char	**tab;
	char	*line;
	int		i;

	carte = open(argv, O_RDONLY, 0777);
	i = 0;
	tab = NULL;
	line = get_next_line(carte);
	tab = tab_join(tab, line);
	while (line)
	{
		line = get_next_line(carte);
		tab = tab_join(tab, line);
		i++;
	}
	tab[i] = ft_strjoin(tab[i], "\n");
	return (tab);
}



int main(int argc, char **argv)
{

	char **tab;
	t_map	*carte;

	carte = malloc(sizeof (t_map));
	tab = NULL;

	if (argc)
	{
		tab = map(argv[1]);
		//print_tab(tab);
	}

	tab = tab_join(tab, "Allo\n");
	print_tab(tab);

	//check_map(tab, carte);
		

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