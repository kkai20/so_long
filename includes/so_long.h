#ifndef SO_LONG_H
#define SO_LONG_H
#define WINDOW_WIDTH 1024
#define WINDOW_HIGHT 860

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_imags
{
	GOAL,
	WALL,
	ITEM,
	FREE,
	PLAYER,
	E_IMAGE_COUNT
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

#define TILE_SIZE 64
#define ROWS 8
#define COLS 10
#define WIDTH COLS * TILE_SIZE
#define HEIGHT ROWS * TILE_SIZE

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

#endif
