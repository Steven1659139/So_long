#include "so_long.h"

/* 
	TO_DO

	- gérer les espaces vides en fin de fichier OK
	- seg_fault quand pas d'argument OK
	- .ber obligatoire OK
	- longueur des lignes uniformes OK




*/



void	print_tab(char **tab)
{
	int	i;

	if (!*tab)
		return;

	i = -1;
	while (tab[++i])
		printf("%s", tab[i]);
	//printf("\n");
}

int	check_edge(char *line, t_map *map)
{
	if (ft_strlen(line) != map->len_line)
		return (0);

	while (*line != '\n' && *line != '\0')
	{
		if (*line != '1')
			return (0);
		line++;
	}
	return (1);
}

int	check_line(char *line, t_map *map)
{
	if (map->len_line != ft_strlen(line))
		return (0);

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
	map->nb_player = 0;
	map->len_line = ft_strlen(tab[i]);
	map->nb_line = tab_length(tab);
	if (!check_edge(tab[i++], map))
		yo_its_wrong("Le haut de la carte n'est pas fermée.");
	while (i < (map->nb_line - 1))
	{
		if (!check_line(tab[i++], map))
			yo_its_wrong("Carte non valide");
	}
	if (!check_edge(tab[i], map))
		yo_its_wrong("Le bas de la carte n'est pas fermé.");

	if (map->nb_collect < 1)
		yo_its_wrong("Il doit y avoir des collectibles.");
	printf("nb_joueur = %d\n", map->nb_player);
	if (map->nb_player < 1 || map->nb_player > 1)
		yo_its_wrong("Il doit y avoir exactement 1 joueur.");
	if (map->nb_exit < 1)
		yo_its_wrong("Il doit y avoir une sortie.");
	map->col_on_map = map->nb_collect;
	map->nb_move = 0;
}
