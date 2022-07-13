/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:46:14 by slavoie           #+#    #+#             */
/*   Updated: 2022/07/04 14:46:22 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (*line != '0' && *line != '1' && *line != 'E' \
		&& *line != 'C' && *line != 'P')
			return (0);
		if (*line == 'E')
			map->nb_exit++;
		if (*line == 'C')
			map->nb_collect++;
		if (*line == 'P')
			map->nb_player++;
		line++;
	}
	line--;
	if (*line != '1')
		return (0);
	return (1);
}

void	check_map(t_map *map)
{
	int	i;

	if (!map->map)
		clean(map, "Le fichier est vide.\n", 1 );
	map->len_line = ft_strlen(map->map[0]);
	map->nb_line = tab_length(map->map);
	i = 0;
	if (!check_edge(map->map[i++], map))
		clean(map, "Le haut de la carte n'est pas fermée.\n", 1);
	while (i < (map->nb_line - 1))
	{
		if (!check_line(map->map[i++], map))
			clean(map, "Carte non valide\n", 1);
	}
	if (!check_edge(map->map[i], map))
		clean(map, "Le bas de la carte n'est pas fermé.\n", 1);
	if (map->nb_collect < 1)
		clean(map, "Il doit y avoir des collectibles.\n", 1);
	if (map->nb_player < 1 || map->nb_player > 1)
		clean(map, "Il doit y avoir exactement 1 joueur.\n", 1);
	if (map->nb_exit < 1)
		clean(map, "Il doit y avoir une sortie.\n", 1);
	

}
