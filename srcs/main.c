#include "so_long.h"

int	my_close(t_vars *game)
{
	(void)game;
	printf("error\n");
	exit(0);
}

void	check_map(t_vars *game)
{
	if (game->itemNum <= 0)
		my_close(game);
	if (game->playerNum != 1)
		my_close(game);
	if (game->goalNum <= 0)
		my_close(game);
}

int	main(void)
{
	t_vars	*game;

	game = (t_vars *)calloc(sizeof(t_vars), 1);
	game->key_flag = 1;
	get_map_size(game);
	game->map = (int **)calloc(sizeof(int *), game->rows + 1);
	for (int i = 0; i < game->rows; i++)
	{
		game->map[i] = (int *) calloc(sizeof(int), game->cols + 1);
	}
	read_map(game);
	for (int i = 0; i < game->rows; i++)
	{
		for (int j = 0; j < game->cols; j++)
		{
			if (game->map [i][j] == ITEM)
				game->itemNum++;
			if (game->map[i][j] == PLAYER)
			{
				game->playerNum++;
				game->player_x = j;
				game->player_y = i;
				game->map[i][j] = FREE;
			}
			if (game->map[i][j] == GOAL)
				game->goalNum++;
		}
	}
	check_map(game);
	make_window(game);
	init_images(game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 1, &deal_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 1, &my_close, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}
