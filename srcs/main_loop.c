/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:38:38 by kkai              #+#    #+#             */
/*   Updated: 2022/09/10 21:51:57 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*int main_loop(t_vars *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (i == game->player_y && j == game->player_x)
				mlx_put_image_to_window(game->mlx, game->win, game->images[PLAYER],
				TILE_SIZE * game->player_x, TILE_SIZE * game->player_y);
			else
				mlx_put_image_to_window(game->mlx, game->win,
				game->images[game->map_line], TILE_SIZE * j, TILE_SIZE * i);
			j++;
		}
		i++;
	}
	return (0);
}
*/
