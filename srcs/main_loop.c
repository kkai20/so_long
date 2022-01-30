/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:58:32 by kkai              #+#    #+#             */
/*   Updated: 2022/01/30 18:40:29 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main_loop(t_vars *game)
{
	int		i;
	int		j;

	// if (game->key_flag == 1 || 1)
	if (1)
	{
		i = 0;
				mlx_put_image_to_window(game->mlx, game->win, game->images[PLAYER],
				TILE_SIZE * game->player_x, TILE_SIZE * game->player_y);
		while (i < game->rows)
		{
			j = 0;
			while (j < game->cols)
			{
				printf("%d\n", game->map[i][j]);
				if (game->map[i][j] != PLAYER)
					{
						// printf("hello\n");
						mlx_put_image_to_window(game->mlx, game->win,
							game->images[game->map[i][j]],
							TILE_SIZE * j, TILE_SIZE * i);
					}
					j++;
				}
			i++;
		}
	// 	mlx_put_image_to_window(game->mlx, game->win, game->images[PLAYER],
	// 		TILE_SIZE * game->player_x, TILE_SIZE * game->player_y);
	}
	// game->key_flag = 0;
	return (0);
}
