#include "so_long.h"

void	clean(t_map *map, char *str, int error)
{
	int	i;

	i = 0;

	if (map->map)
		table_flip(map->map);
	if (map->first_cel)
		free_map(map);
	if (map->pos_collect)
		free(map->pos_collect);
	if (map->pos_wall)
		free(map->pos_wall);
	if (map->pos_exit)
		free(map->pos_exit);
	if (map->player.sprite)
		ft_lstclear(&map->player.sprite, NULL);
	// if (map->mlx)
	// 	image_destroyer(map);
	// if (map->map)
	// {

	// 	while (map->map[i])
	// 	{
	// 		// printf("%d- %s", i, map->map[i]);
	// 		free(map->map[i++]);
	// 	}
	// 	// printf("%d- %s", i, map->map[i]);
	// 	free(map->map[i]);
	// 	free(map->map);
	// }
	
	// while (map->map[i])
	// {
	// 	printf("%s", map->map[i++]);
	// }
	
	free(map->mlx);

	free(map);
	if (error == 1)
		yo_its_wrong(str);


	exit(0);



}

void	free_map(t_map *map)
{
	t_case	*cel;
	t_case	*next_line;
	t_case	*temp;

	cel = map->first_cel;
	while (cel->down)
	{
		next_line = cel->down;
		while (cel->right)
		{
			temp = cel;
			cel = cel->right;
			free(temp);
		}
		cel = next_line;
	}
}

void	image_destroyer(t_map *map)
{
	mlx_destroy_image(map->mlx, &map->sprite.p_sprite_1);
	mlx_destroy_image(map->mlx, &map->sprite.p_sprite_2);
	mlx_destroy_image(map->mlx, &map->sprite.p_sprite_3);
	mlx_destroy_image(map->mlx, &map->sprite.p_sprite_4);
	mlx_destroy_image(map->mlx, &map->sprite.ultime_1);
	mlx_destroy_image(map->mlx, &map->sprite.ultime_2);
	mlx_destroy_image(map->mlx, &map->sprite.ouach_D1);
	mlx_destroy_image(map->mlx, &map->sprite.ouach_U1);
	mlx_destroy_image(map->mlx, &map->sprite.ouach_L1);
	mlx_destroy_image(map->mlx, &map->sprite.ouach_R1);

	mlx_destroy_image(map->mlx, &map->sprite.floor);
	mlx_destroy_image(map->mlx, &map->sprite.collectible);
	mlx_destroy_image(map->mlx, &map->sprite.wall);
	mlx_destroy_window(map->mlx, map->mlx_win);
}