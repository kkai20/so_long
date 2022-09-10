/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:58:24 by kkai              #+#    #+#             */
/*   Updated: 2022/09/10 13:41:49 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	make_window(t_vars *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		my_close(game, "Error\n malloc error\n");
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	if (game->win == NULL)
		my_close(game, "Error\n malloc error\n");
}

void	init_images(t_vars *game)
{
	int		img_width;
	int		img_height;

	game->images[GOAL] = mlx_xpm_file_to_image(game->mlx, GOAL_PATH,
			&img_width, &img_height);
	game->images[WALL] = mlx_xpm_file_to_image(game->mlx, WALL_PATH,
			&img_width, &img_height);
	game->images[ITEM] = mlx_xpm_file_to_image(game->mlx, ITEM_PATH,
			&img_width, &img_height);
	game->images[PLAYER] = mlx_xpm_file_to_image(game->mlx, PLAYER_PATH,
			&img_width, &img_height);
	game->images[FREE] = mlx_xpm_file_to_image(game->mlx, FREE_PATH,
			&img_width, &img_height);
	if (!game->images[GOAL] || !game->images[WALL] || !game->images[ITEM]
		|| !game->images[PLAYER] || !game->images[FREE])
		my_close(game, "Error\n missing imagepath\n");
}
