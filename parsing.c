#include "so_long.h"

void	print_tab(char **tab)
{
	int	i;

	if (!*tab)
		return;

	i = -1;
	while (tab[++i])
		printf("%s", tab[i]);
	printf("\n");
}

int	check_edge(char *line)
{
	while (*line != '\n')
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
	
	while (*line != '\n')
	{
		if (*line != '0' && *line != '1' && *line != 'E' && *line != 'C' && *line != 'P')
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

void check_map(char **tab, t_map *map)
{
	int	i;
	int len;

	i = 0;
	len = tab_length(tab);
	printf("len = %d\n", len);

	if (!check_edge(tab[i++]))
		yo_its_wrong("La carte n'est pas fermée.");
	while (i < (len - 2))
	{
		printf("i = %d\n", i);
		if (!check_line(tab[i++], map))
		{
			printf("%s\n", tab[i]);



			yo_its_wrong("Carte non valide");
		}
	}
	printf("%s\n", tab[i]);

	if (!check_edge(tab[i]))
		yo_its_wrong("La carte n'est pas fermé, bas");








}
