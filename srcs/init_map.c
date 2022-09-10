/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:58:15 by kkai              #+#    #+#             */
/*   Updated: 2022/09/10 16:54:32 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_map(t_vars *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
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
	char	*line;
	int		flag;

	line = NULL;
	fd1 = open(game->map_filepath, O_RDONLY);
	if (fd1 == -1)
		my_close(game, "Error\n open file\n");
	flag = get_next_line(fd1, &line);
	if (flag == -1)
		my_close(game, "Error\n can't read map");
	game->height = 0;
	game->width = ft_strlen(line) - 1;
	game->map_line = ft_mapdup(line);
	free(line);
	while (flag)
	{
		game->height++;
		flag = get_next_line(fd1, &line);
		if (flag)
		{
			game->map_line = ft_mapjoin(game->map_line, line);
		}
		// if (game->width != -1 && game->width != wid)
		// 	my_close(game, "Error\n map is not rectangle\n");
	}
	// free(line);
	close(fd1);
	printf("%s\n", game->map_line);
}

void	read_map_loop_handler(t_vars *game, char *line, int height, int width)
{
	if (line[width] == '0')
		game->map[height][width] = FREE;
	else if (line[width] == '1')
		game->map[height][width] = WALL;
	else if (line[width] == 'C')
		game->map[height][width] = ITEM;
	else if (line[width] == 'E')
		game->map[height][width] = GOAL;
	else if (line[width] == 'P')
		game->map[height][width] = PLAYER;
	else
	my_close(game, "Error\n illegal charactor.\n");
	if (height == 0 || height == game->height - 1
		|| width == 0 || width == game->width - 1)
	{
		if (game->map[height][width] != WALL)
			my_close(game, "Error\n map is not surrounded WALLs\n");
	}
}

void	read_map(t_vars	*game)
{
	int		h;
	int		wid;

	h = 0;
	while (h < game->height)
	{
		wid = 0;
		while (wid < game->width)
		{
			read_map_loop_handler(game, game->map_line, game->height, game->width);
			wid++;
		}
		h++;
	}
}


/* void	read_map(t_vars *game)
{
	int		fd2;
	char	*line;
	int		height;
	int		width;
	int		ret;

	fd2 = open(game->map_filepath, O_RDONLY);
	if (fd2 == -1)
		my_close(game, "Error\n error open file\n");
	height = 0;
	line = NULL;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd2, &line);
		if (ret == -1)
			my_close(game, "Error\n can't read map");
		width = -1;
		while (line[++width] != '\0')
		{
			printf("%d\n", width);
			read_map_loop_handler(game, line, height, width);
		}
		free(line);
		height++;
	}
	// free(line);
	close(fd2);
}*/
