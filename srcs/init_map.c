/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:58:15 by kkai              #+#    #+#             */
/*   Updated: 2022/01/31 01:46:47 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_map(t_vars *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->rows)
	{
		j = -1;
		while (++j < game->cols)
		{
			if (game->map[i][j] == ITEM)
				game->itemNum++;
			if (game->map[i][j] == PLAYER)
			{
				game->playerNum++;
				game->player_x = j;
				game->player_y = i;
				game->map[i][j] = FREE;
			}
			if (game->map[i][j] == GOAL)
				game->goalNum++;
		}
	}
}

void	get_map_size(t_vars *game)
{
	int		fd1;
	char	*receiver;
	int		column;
	int		ret;

	receiver = NULL;
	fd1 = open(game->map_filepath, O_RDONLY);
	if (fd1 == -1)
		my_close(game, "error open file\n");
	game->rows = 0;
	game->cols = -1;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd1, &receiver);
			  // if (get_next_line(fd1, &receiver) != 1)
			  // 	break ;
		if (ret == -1)
			my_close(game, "Error: can't read map");
		game->rows++;
		column = 0;
		while (receiver[column] != '\0')
			column++;
		game->cols = column;
		if (game->cols != -1 && game->cols != column)
			my_close(game, "Error: map is not rectangle\n");
		free(receiver);
	}
	// free(receiver);
	close(fd1);
}

void	read_map_loop_handler(t_vars *game, char *receiver, int row, int column)
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
		my_close(game, "Error: illegal charactor.\n");
	if (row == 0 || row == game->rows - 1
		|| column == 0 || column == game->cols - 1)
	{
		if (game->map[row][column] != WALL)
			my_close(game, "Error: map is not surrounded WALLs\n");
	}
}

void	read_map(t_vars *game)
{
	int		fd2;
	char	*receiver;
	int		row;
	int		column;
	int		ret;

	fd2 = open(game->map_filepath, O_RDONLY);
	if (fd2 == -1)
		my_close(game, "error open file\n");
	row = 0;
	receiver = NULL;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd2, &receiver);
		if (ret == -1)
			my_close(game, "Error: can't read map");
		column = -1;
		while (receiver[++column] != '\0')
		{
			printf("%d\n", column);
			read_map_loop_handler(game, receiver, row, column);
		}
		free(receiver);
		row++;
	}
	// free(receiver);
	close(fd2);
}
