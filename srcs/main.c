#include "so_long.h"

int 	map[8][10] = {
					{WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
					{WALL,PLAYER,FREE,FREE,FREE,FREE,FREE,FREE,FREE,WALL},
					{WALL,FREE,FREE,FREE,FREE,FREE,FREE,FREE,FREE,WALL},
					{WALL,FREE,FREE,FREE,FREE,FREE,FREE,FREE,FREE,WALL},
					{WALL,FREE,FREE,FREE,FREE,FREE,FREE,FREE,FREE,WALL},
					{WALL,FREE,FREE,FREE,FREE,FREE,FREE,GOAL,FREE,WALL},
					{WALL,FREE,FREE,FREE,FREE,FREE,FREE,FREE,FREE,WALL},
					{WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
					};

int g_player_x = 4;
int g_player_y = 0;
int g_key_flag = 1;




int my_close(t_vars *game)
{
	exit(0);
}


void	make_window(t_vars *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "so_long");
}

int deal_key(int key_code, t_vars *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	else if (key_code == KEY_W)
		g_player_y -= 1;
	else if (key_code == KEY_S)
		g_player_y += 1;
	else if (key_code == KEY_A)
		g_player_x -= 1;
	else if (key_code == KEY_D)
		g_player_x += 1;
	g_key_flag = 1;
	return (0);
}

int main_loop(t_vars *game)
{
	void	*mlx = game->mlx;
	void	*mlx_win = game->win;
	void	*goal_img;
	void	*wall_img;
	void	*item_img;
	void	*player_img;
	void	*free_img;

	int		img_width;
	int		img_height;

	char	*goal_path = "./images/goal.xpm";
	char	*wall_path = "./images/wall.xpm";
	char	*item_path = "./images/item.xpm";
	char	*player_path = "./images/player.xpm";
	char	*free_path = "./images/free.xpm";



	if (g_key_flag == 1)
	{
		void	*images[E_IMAGE_COUNT];


		images[GOAL] = mlx_xpm_file_to_image(mlx, goal_path, &img_width, &img_height);

		images[WALL]= mlx_xpm_file_to_image(mlx, wall_path, &img_width, &img_height);
		images[ITEM] = mlx_xpm_file_to_image(mlx, item_path, &img_width, &img_height);
		images[PLAYER] = mlx_xpm_file_to_image(mlx, player_path, &img_width, &img_height);
		images[FREE] = mlx_xpm_file_to_image(mlx, free_path, &img_width, &img_height);

		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				mlx_put_image_to_window(mlx, mlx_win, images[map[i][j]], TILE_SIZE * j, TILE_SIZE * i);
			}
		}
		mlx_put_image_to_window(mlx, mlx_win, images[PLAYER], TILE_SIZE * g_player_x, TILE_SIZE * g_player_y);
	}
	g_key_flag = 0;
	return (0);
}

int	main(void)
{
	t_vars *game = (t_vars *)malloc(sizeof(t_vars));

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (map[i][j]== PLAYER)
			{
				g_player_x = i;
				g_player_y = j;
			}
		}
	}

	make_window(game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 1, &deal_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 1, &my_close, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}
