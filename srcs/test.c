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

int	main(void)
{
	t_vars	game;
	char map[][2] = {{'1','0'},{'0','1'}};
	void	*mlx;
	void	*goal_img;
	void	*wall_img;
	void	*item_img;
	void	*player_img;
	void	*free_img;
	void	*mlx_win;
	char	*goal_path = "./images/goal.xpm";
	char	*wall_path = "./images/wall.xpm";
	char	*item_path = "./images/item.xpm";
	char	*player_path = "./images/player.xpm";
	char	*free_path = "./images/free.xpm";

	int		img_width;
	int		img_height;

	printf("%d\n %d\n : %c\n", 0,0,map[0][0]);

	mlx = mlx_init();
	goal_img = mlx_xpm_file_to_image(mlx, goal_path, &img_width, &img_height);
	wall_img = mlx_xpm_file_to_image(mlx, wall_path, &img_width, &img_height);
	item_img = mlx_xpm_file_to_image(mlx, item_path, &img_width, &img_height);
	player_img = mlx_xpm_file_to_image(mlx, player_path, &img_width, &img_height);
	free_img = mlx_xpm_file_to_image(mlx, free_path, &img_width, &img_height);
	mlx_win = mlx_new_window(mlx, 320, 320, "so_long");


	mlx_put_image_to_window(mlx, mlx_win, goal_img, 64 * 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, wall_img, 64 * 1, 0);
	mlx_put_image_to_window(mlx, mlx_win, item_img, 64 * 2, 0);
	mlx_put_image_to_window(mlx, mlx_win, free_img, 64 * 3, 0);
	mlx_put_image_to_window(mlx, mlx_win, player_img, 64 * 4, 0);
	mlx_hook(mlx_win, X_EVENT_KEY_EXIT, 1, &my_close, &game);

	mlx_loop(mlx);
}
