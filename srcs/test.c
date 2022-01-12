#define WINDOW_WIDTH 1024
#define WINDOW_HIGHT 860

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};


int g_player_x = 4;
int g_player_y = 0;
int g_key_flag = 1;

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17 // Exit program key code

//キーコードはwsl ubuntu仕様です。
// minilibx-linuxディレクトリ内の/test/mlx-testでそれぞれの環境のキーコードを確認してください。

#define KEY_ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

#define TILE_SIZE 32
#define ROWS 11
#define COLS 15
#define WIDTH COLS *TILE_SIZE
#define HEIGHT ROWS *TILE_SIZE

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int my_close(t_vars *game)
{
	exit(0);
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
		goal_img = mlx_xpm_file_to_image(mlx, goal_path, &img_width, &img_height);
		wall_img = mlx_xpm_file_to_image(mlx, wall_path, &img_width, &img_height);
		item_img = mlx_xpm_file_to_image(mlx, item_path, &img_width, &img_height);
		player_img = mlx_xpm_file_to_image(mlx, player_path, &img_width, &img_height);
		free_img = mlx_xpm_file_to_image(mlx, free_path, &img_width, &img_height);

		int i;
		int j;
		for (i = 0; i < 5;i++)
		{
			for (j=0; j<5; j++)
			{
				mlx_put_image_to_window(mlx, mlx_win, free_img, 64 * i, 64 * j);
			}
		}
		mlx_put_image_to_window(mlx, mlx_win, goal_img, 64 * 0, 0);
		mlx_put_image_to_window(mlx, mlx_win, wall_img, 64 * 1, 0);
		mlx_put_image_to_window(mlx, mlx_win, item_img, 64 * 2, 0);
		mlx_put_image_to_window(mlx, mlx_win, free_img, 64 * 3, 0);
		mlx_put_image_to_window(mlx, mlx_win, player_img, 64 * g_player_x, 64 * g_player_y);
	}
	g_key_flag = 0;
	return (0);
}

int	main(void)
{
	t_vars	*game = (t_vars *)malloc(sizeof(t_vars));
	char map[][2] = {{'1','0'},{'0','1'}};

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 640, 640, "so_long");

	mlx_hook(game->win, X_EVENT_KEY_PRESS, 1, &deal_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 1, &my_close, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}
