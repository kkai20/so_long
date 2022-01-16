#include "so_long.h"

void	get_map_size(t_vars *game)
{
	int		fd1;
	char	*receiver;
	int		column;
	int		ret_value;

	receiver = NULL;
	fd1 = open("./maps/sample1.ber", O_RDONLY);
	game->rows = 0;
	game->cols = -1;
	while (1)
	{
		ret_value = get_next_line(fd1, &receiver);
		if (ret_value != 1)
			break ;
		game->rows++;
		column = 0;
		while (receiver[column] != '\0')
		{
			column++;
		}
		if (game->cols != -1 && game->cols != column)
			my_close(game, "map is not rectangle");
		game->cols = column;
		free(receiver);
	}
	close(fd1);
}

void	read_map(t_vars *game)
{
	int		fd2;
	char	*receiver;
	int		row;
	int		column;
	int		ret_value;

	fd2 = open("./maps/sample1.ber", O_RDONLY);
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
				game->map[row][column] = FREE;
			else if (receiver[column] == '1')
				game->map[row][column] = WALL;
			else if (receiver[column] == 'C')
				game->map[row][column] = ITEM;
			else if (receiver[column] == 'E')
				game->map[row][column] = GOAL;
			else if (receiver[column] == 'P')
				game->map[row][column] = PLAYER;
			else
				my_close(game, "illegal charactor.");
		}
		free(receiver);
		row++;
	}
	close(fd2);
}
