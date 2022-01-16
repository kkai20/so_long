#include "so_long.h"


int **map;

int g_player_x = 4;
int g_player_y = 0;
int g_key_flag = 1;
int g_itemNum = 0;
int	g_step_count = 0;
int	g_rows = 8;
int	g_cols = 10;
void	*images[E_IMAGE_COUNT];


int my_close(t_vars *game)
{
	(void)game;
	exit(0);
}


void	make_window(t_vars *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, g_cols * TILE_SIZE, g_rows * TILE_SIZE, "so_long");
}

void	init_images(t_vars *game)
{
	int		img_width;
	int		img_height;

	images[GOAL] = mlx_xpm_file_to_image(game->mlx, GOAL_PATH, &img_width, &img_height);
	images[WALL]= mlx_xpm_file_to_image(game->mlx, WALL_PATH, &img_width, &img_height);
	images[ITEM] = mlx_xpm_file_to_image(game->mlx, ITEM_PATH, &img_width, &img_height);
	images[PLAYER] = mlx_xpm_file_to_image(game->mlx, PLAYER_PATH, &img_width, &img_height);
	images[FREE] = mlx_xpm_file_to_image(game->mlx, FREE_PATH, &img_width, &img_height);
}


int	deal_key(int key_code, t_vars *game)
{
	int old_player_x;
	int old_player_y;

	old_player_x = g_player_x;
	old_player_y = g_player_y;
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
	if (map[g_player_y][g_player_x] == WALL)
	{
		g_player_x = old_player_x;
		g_player_y = old_player_y;
	}
	if (g_player_x != old_player_x || g_player_y != old_player_y)
	{
		g_step_count++;
		printf("%d\n", g_step_count);
	}
	if(map[g_player_y][g_player_x] == ITEM)
	{
		g_itemNum--;
		map[g_player_y][g_player_x] = FREE;
	}
	if (map[g_player_y][g_player_x] == GOAL && g_itemNum <= 0)
	{
		my_close(game);
	}

	return (0);
}

int main_loop(t_vars *game)
{
	void	*mlx = game->mlx;
	void	*mlx_win = game->win;


	if (g_key_flag == 1)
	{
		for (int i = 0; i < g_rows; i++)
		{
			for (int j = 0; j < g_cols; j++)
			{
				mlx_put_image_to_window(mlx, mlx_win, images[map[i][j]], TILE_SIZE * j, TILE_SIZE * i);
			}
		}
		mlx_put_image_to_window(mlx, mlx_win, images[PLAYER], TILE_SIZE * g_player_x, TILE_SIZE * g_player_y);
	}
	g_key_flag = 0;
	return (0);
}

void get_map_size(t_vars *game)
{
	int	fd1;
	char	*receiver = NULL;
	int column;
	int ret_value;

	(void)game;
	fd1 = open("./maps/sample1.ber", O_RDONLY);
	printf("fd1 = %d\n", fd1);

	g_rows = 0;
	while(1)
	{
		ret_value = get_next_line(fd1, &receiver);
		if (ret_value != 1)
			break ;
		g_rows++;
		column = 0;
		while (receiver[column] != '\0')
		{
			column++;
		}
		g_cols = column;
		free(receiver);
	}
	printf("rows=%d\n", g_rows);
	printf("cols=%d\n", g_cols);
	close(fd1);
}

int	main(void)
{
	int	fd2;
	char	*receiver = NULL;
	int row;
	int column;
	int ret_value;

	t_vars *game = (t_vars *)malloc(sizeof(t_vars));

	get_map_size(game);
	map = (int **)calloc(sizeof(int *), g_rows+1);
	for (int i= 0;i<g_rows; i++)
	{
		map[i]=(int *) calloc(sizeof(int),g_cols+1);
	}


	fd2 = open("./maps/sample1.ber", O_RDONLY);
	printf("fd2 = %d\n", fd2);

	row = 0;
	receiver = NULL;
	while (1)
	{
		ret_value = get_next_line(fd2, &receiver);
		if (ret_value != 1)
			break ;
		column = -1;
		while (receiver[++column] != '\0')
		{
			if (receiver[column] == '0')
				map[row][column] = FREE;
			if (receiver[column] == '1')
				map[row][column] = WALL;
			if (receiver[column] == 'C')
				map[row][column] = ITEM;
			if (receiver[column] == 'E')
				map[row][column] = GOAL;
			if (receiver[column] == 'P')
				map[row][column] = PLAYER;
		}
		free(receiver);
		row++;
		close(fd2);
	}


	for (int i = 0; i < g_rows; i++)
	{
		for (int j = 0; j < g_cols; j++)
		{
			if (map [i][j] == ITEM)
				g_itemNum++;
			if (map[i][j]== PLAYER)
			{
				g_player_x = j;
				g_player_y = i;
				map[i][j] = FREE;
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
