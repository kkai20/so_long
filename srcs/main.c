#include "so_long.h"



int my_close(t_vars *game)
{
	(void)game;
	exit(0);
}

int	deal_key(int key_code, t_vars *game)
{
	int	old_player_x;
	int	old_player_y;

	old_player_x = game->player_x;
	old_player_y = game->player_y;
	if (key_code == KEY_ESC)
		exit(0);
	else if (key_code == KEY_W)
		game->player_y -= 1;
	else if (key_code == KEY_S)
		game->player_y += 1;
	else if (key_code == KEY_A)
		game->player_x -= 1;
	else if (key_code == KEY_D)
		game->player_x += 1;
	game->key_flag = 1;
	if (game->map[game->player_y][game->player_x] == WALL)
	{
		game->player_x = old_player_x;
		game->player_y = old_player_y;
	}
	if (game->player_x != old_player_x || game->player_y != old_player_y)
	{
		game->step_count++;
		printf("%d\n", game->step_count);
	}
	if(game->map[game->player_y][game->player_x] == ITEM)
	{
		game->itemNum--;
		game->map[game->player_y][game->player_x] = FREE;
	}
	if (game->map[game->player_y][game->player_x] == GOAL && game->itemNum <= 0)
	{
		my_close(game);
	}
	return (0);
}

int main_loop(t_vars *game)
{
	void	*mlx = game->mlx;
	void	*mlx_win = game->win;

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



int	main(void)
{
	t_vars *game;
	game = (t_vars *)malloc(sizeof(t_vars));

	game->key_flag = 1;
	get_map_size(game);
	game->map = (int **)calloc(sizeof(int *), game->rows+1);
	for (int i= 0;i<game->rows; i++)
	{
		game->map[i]=(int *) calloc(sizeof(int),game->cols+1);
	}

	read_map(game);
	for (int i = 0; i < game->rows; i++)
	{
		for (int j = 0; j < game->cols; j++)
		{
			if (game->map [i][j] == ITEM)
				game->itemNum++;
			if (game->map[i][j]== PLAYER)
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
