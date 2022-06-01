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

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);

}