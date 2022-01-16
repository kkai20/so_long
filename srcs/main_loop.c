#include "so_long.h"

int	main_loop(t_vars *game)
{
	void *mlx = game->mlx;
	void *mlx_win = game->win;

	if (game->key_flag == 1)
	{
		for (int i = 0; i < game->rows; i++)
		{
			for (int j = 0; j < game->cols; j++)
			{
				mlx_put_image_to_window(mlx, mlx_win, game->images[game->map[i][j]], TILE_SIZE * j, TILE_SIZE * i);
			}
		}
		mlx_put_image_to_window(mlx, mlx_win, game->images[PLAYER], TILE_SIZE * game->player_x, TILE_SIZE * game->player_y);
	}
	game->key_flag = 0;
	return (0);
}
