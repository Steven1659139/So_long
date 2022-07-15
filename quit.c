#include "so_long.h"

void	clean(t_map *map, char *str, int error)
{


	if (map->map)
		table_flip(map->map);
	if (map->pos_collect)
	{
		free(map->pos_collect);
		printf("free pos_collect\n");
	}
	if (map->pos_wall)
	{

		free(map->pos_wall);
		printf("free pos_wall\n");
	}
	if (map->pos_exit)
	{

		free(map->pos_exit);
		printf("free pos_exit\n");
	}
	if (map->player.sprite)
		ft_lstclear(&map->player.sprite, NULL);
	if (map->mlx)
		image_destroyer(map);
	if (map->first_cel)
		free_map(map);

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
	printf("mlx free \n");
	// free(map->mlx_win);

	free(map);
	printf("struct free\n");
	if (error == 1)
		yo_its_wrong(str);


	exit(0);



}

void	free_map(t_map *map)
{
	t_case	*cel;
	t_case	*next_line;
	t_case	*temp;
	int i;

	i = 1;

	cel = map->first_cel;
	while (cel->down)
	{
		next_line = cel->down;
		while (cel->right)
		{
			temp = cel;
			cel = cel->right;
			free(temp);
			printf("case %d free\n", i++);
		}
		free(cel);
		printf("case %d free\n", i++);
		cel = next_line;
	}
		while (cel->right)
	{
		temp = cel;
		cel = cel->right;
		free(temp);
		printf("case %d free\n", i++);
	}
	free(cel);
	printf("case %d free\n", i++);
}

void	image_destroyer(t_map *map)
{
	mlx_destroy_image(map->mlx, map->sprite.p_sprite_1.img);
	mlx_destroy_image(map->mlx, map->sprite.p_sprite_2.img);
	mlx_destroy_image(map->mlx, map->sprite.p_sprite_3.img);
	mlx_destroy_image(map->mlx, map->sprite.p_sprite_4.img);
	mlx_destroy_image(map->mlx, map->sprite.ultime_1.img);
	mlx_destroy_image(map->mlx, map->sprite.ultime_2.img);
	mlx_destroy_image(map->mlx, map->ouachcaca.sprite_down.img);
	mlx_destroy_image(map->mlx, map->ouachcaca.sprite_up.img);
	mlx_destroy_image(map->mlx, map->ouachcaca.sprite_left.img);
	mlx_destroy_image(map->mlx, map->ouachcaca.sprite_right.img);
	mlx_destroy_image(map->mlx, map->sprite.floor.img);
	mlx_destroy_image(map->mlx, map->sprite.collectible.img);
	mlx_destroy_image(map->mlx, map->sprite.wall.img);
	mlx_destroy_image(map->mlx, map->sprite.exit.img);
	mlx_destroy_image(map->mlx, map->sprite.get_rekt.img);
	mlx_destroy_window(map->mlx, map->mlx_win);
	printf("image et window détruites \n");
}