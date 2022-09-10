/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:58:15 by kkai              #+#    #+#             */
/*   Updated: 2022/09/10 23:42:42 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_map(t_vars *game)
{
	int		i;

	i = 0;
	while (i >=0 && (size_t)i < ft_strlen(game->map_line))
	{
		if (game->map_line[i] == ITEM)
			game->itemNum++;
		if (game->map_line[i] == PLAYER)
		{
			game->playerNum++;
			// game->player_x = j;
			game->player_y = i;
			game->map_line[i] = FREE;
		}
		if (game->map_line[i] == GOAL)
			game->goalNum++;
		i++;
	}
}


void	read_map(t_vars *game)
{
	int		fd;
	char	*line;
	int		flag;

	fd = ft_open(game->map_filepath, O_RDONLY);
	flag = get_next_line(fd, &line);
	if (flag == -1)
		my_close(game, "Error\n Can't read map");
	game->height = 0;
	game->width = ft_strlen(line) - 1;
	game->map_line = ft_mapdup(line);
	free(line);
	while (flag > 0)
	{
		game->height++;
		flag = get_next_line(fd, &line);
		if (flag >= 0)
		{
			game->map_line = ft_mapjoin(game->map_line, line);
		}
		printf("finish\n");
	}
	ft_close(fd);
}

void	check_wall(t_vars *game)
{
	int		i;

	i = 0;
	while (i >=0 && (size_t)i < ft_strlen(game->map_line))
	{
		if (i < game->width)
		{
			if (game->map_line[i] != WALL)
				my_close(game, "Error\n map is not surrounded WALLs\n");
		}
		else if (i % game->width == 0 || i % game->width == game->width - 1)
		{
			if (game->map_line[i] != WALL)
				my_close(game, "Error\n map is not surrounded WALLs\n");
		}
		else if ( i >= 0 && (size_t)i > ft_strlen(game->map_line) - game->width)
		{
			if (game->map_line[i] != WALL)
				my_close(game, "Error\n map is not surrounded WALLs\n");
		}
		i++;
	}
}

void	put_image_handler(t_vars *game, char *map_line, int wid, int hei)
{
	if (map_line[hei * game->width + wid] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->images[FREE], TILE_SIZE * wid, TILE_SIZE * hei);
	}
	else if (map_line[hei * game->width + wid] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->images[WALL], TILE_SIZE * wid, TILE_SIZE * hei);
	}
	else if (map_line[hei * game->width + wid] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->images[ITEM], TILE_SIZE * wid, TILE_SIZE * hei);
	else if (map_line[hei * game->width + wid] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->images[GOAL], TILE_SIZE * wid, TILE_SIZE * hei);
	else if (map_line[hei * game->width + wid] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->images[PLAYER], TILE_SIZE * wid, TILE_SIZE * hei);
	else
		my_close(game, "Error\n illegal charactor.\n");
	// if (height == 0 || height == game->height - 1
	// 	|| width == 0 || width == game->width - 1)
	// {
	// 	if (game->map[height][width] != WALL)
	// 		my_close(game, "Error\n map is not surrounded WALLs\n");
	// }
}

void	set_map(t_vars *game)
{
	int hei;
	int wid;

	hei = 0;
	while (hei < game->height)
	{
		wid = 0;
		while (wid < game->width)
		{
			put_image_handler(game, game->map_line, wid, hei);
			wid++;
		}
		hei++;
	}
}
