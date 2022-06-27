#include "so_long.h"

int	tab_length(char **tab)
{
	int	i;

	i = 0;

	while (tab[i])
	{
		i++;
	}

	return (i);
}

char	**tab_trunc(char **tab, char *str)
{
	int	i;
	char	**new_tab;

	i = 0;
	new_tab = NULL;

	if (!tab)
		return (0);
	while (ft_strncmp(tab[i], str, ft_strlen(tab[i])) != 0)
	{
		new_tab = tab_join(new_tab, tab[i]);
		i++;
	}
	new_tab[i] = NULL;
	table_flip(tab);
	return (new_tab);
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
	table_flip(tab);

	return (new_tab);
}


char **set_map(char *argv)
{
	int		map;
	char	**tab;
	char	*line;
	int		i;

	map = open(argv, O_RDONLY, 0777);
	if (map == -1)
		yo_its_wrong("Erreur lors de la lecture du fichier.");
	i = 0;
	tab = NULL;
	line = get_next_line(map);
	tab = tab_join(tab, line);
	while (line)
	{
		line = get_next_line(map);
		tab = tab_join(tab, line);
		if (!ft_strchr(tab[i], '\n'))
			tab[i] = ft_strjoin(tab[i], "\n");
		i++;
	}
	//print_tab(tab);
	tab = tab_trunc(tab, "\n");
	//print_tab(tab);
	

	return (tab);
}



int main(int argc, char **argv)
{

	t_map	*map;

	map = malloc(sizeof (t_map));
	



	if (argc == 2)
	{
		if (ft_strncmp(ft_strchr(argv[1], '.'), ".ber", ft_strlen(argv[1])))
			yo_its_wrong("Le fichier doit être de type .ber");
		
		map->map = set_map(argv[1]);

		//print_tab(tab);
		check_map(map->map, map);
	}

	//tab = tab_join(tab, "Allo\n");
	//print_tab(tab);

	//tab_length(tab);

	map->win_size_x = (ft_strlen(map->map[0]) * 30) - 30;
	map->win_size_y = (tab_length(map->map) * 30);

	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, map->win_size_x, map->win_size_y, "So_long");

	set_image(map, map->mlx);
	print_map(map);

	mlx_loop(map->mlx);
}