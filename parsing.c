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

	i = 0;

	if (!check_edge(tab[i]))
		yo_its_wrong("La carte n'est pas fermée.");
	while (tab[++i])
	{
		printf("%s", tab[i]);
		if (!check_line(tab[i], map))
			yo_its_wrong("Carte non valide");
	}
	if (!check_edge(tab[i]))
		yo_its_wrong("La carte n'est pas fermé, bas");








}
