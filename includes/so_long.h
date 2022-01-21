#ifndef SO_LONG_H
#define SO_LONG_H


#include <unistd.h>
#include <stdio.h>

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



#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17 // Exit program key code

//キーコードはwsl ubuntu仕様です。
// minilibx-linuxディレクトリ内の/test/mlx-testでそれぞれの環境のキーコードを確認してください。

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define GOAL_PATH "./images/goal.xpm"
# define WALL_PATH "./images/wall.xpm"
# define ITEM_PATH "./images/item.xpm"
# define PLAYER_PATH "./images/player.xpm"
# define FREE_PATH "./images/free.xpm"

#define TILE_SIZE 64

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int 	**map;
	int 	player_x;
	int 	player_y;
	int 	key_flag;
	int 	itemNum;
	int		playerNum;
	int		goalNum;
	int		step_count;
	int		rows;
	int		cols;
	void	*images[E_IMAGE_COUNT];
	char	*map_filepath;
}				t_vars;

void	make_window(t_vars *game);
void	init_images(t_vars *game);
void	get_map_size(t_vars *game);
void	read_map(t_vars *game);
int		deal_key(int key_code, t_vars *game);
int		main_loop(t_vars *game);
int	my_close(t_vars *game, char *message);
#endif
