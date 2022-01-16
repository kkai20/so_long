#include "so_long.h"

int	my_close(t_vars *game)
{
	(void)game;
	exit(0);
}

int	main(void)
{
	t_vars	*game;

	game = (t_vars *)malloc(sizeof(t_vars));
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
				game->player_x = j;
				game->player_y = i;
				game->map[i][j] = FREE;
			}
		}
	}
	make_window(game);
	init_images(game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 1, &deal_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 1, &my_close, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}
