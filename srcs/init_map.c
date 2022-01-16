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
			if (receiver[column] == '1')
				game->map[row][column] = WALL;
			if (receiver[column] == 'C')
				game->map[row][column] = ITEM;
			if (receiver[column] == 'E')
				game->map[row][column] = GOAL;
			if (receiver[column] == 'P')
				game->map[row][column] = PLAYER;
		}
		free(receiver);
		row++;
	}
	close(fd2);
}
