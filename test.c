#include "so_long.h"

void	print_tab(char **tab)
{
	int	i;

	if (!*tab)
		return ;
	i = -1;
	while (tab[++i])
		printf("%s", tab[i]);
}

void	set_collectible(t_map *map)
{
	t_case	*cel;
	t_case	*next_line;
	int		i;

	map->pos_collect = malloc(sizeof(t_pos) * map->nb_collect);
	cel = map->first_cel;
	i = 0;
	while (cel->down)
	{
		next_line = cel->down;
		while (cel->right)
		{
			if (cel->state == 'C')
			{
				map->pos_collect[i] = cel->pos;
				i++;
			}
			cel = cel->right;
		}
		cel = next_line;
	}
}








char 	**create_tab()
{
	char	**map;
	char	*line;
	int		nombre_de_ligne;
	int		i;
	int		fd;

	i = 0;

	fd = open("map_file.ber", O_RDONLY, 0777);

	nombre_de_ligne = 5; // juste pour le test, autrement tu dois compter les lignes

	map = malloc(sizeof(char *) * nombre_de_ligne + 1);

	while (i < nombre_de_ligne)
	{
		line = get_next_line(fd);
		map[i] = line;
		// printf("%s", map[i]);
		i++;
	}
	map[i] = NULL;

	return(map);
}

int main(void)
{
	char **tab;

	tab = create_tab();




	print_tab(tab);







}