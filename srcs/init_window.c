/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:58:24 by kkai              #+#    #+#             */
/*   Updated: 2022/09/10 22:44:06 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	make_window(t_vars *game)
{
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height * TILE_SIZE, "so_long");
	if (game->win == NULL)
		my_close(game, "Error\n malloc error\n");
}

void	init_images(t_vars *game)
{
	int		width;
	int		height;

	game->images[GOAL] = mlx_xpm_file_to_image(game->mlx, GOAL_PATH, &width, &height);
	game->images[WALL] = mlx_xpm_file_to_image(game->mlx, WALL_PATH, &width, &height);
	game->images[ITEM] = mlx_xpm_file_to_image(game->mlx, ITEM_PATH, &width, &height);
	game->images[PLAYER] = mlx_xpm_file_to_image(game->mlx, PLAYER_PATH, &width, &height);
	game->images[FREE] = mlx_xpm_file_to_image(game->mlx, FREE_PATH, &width, &height);
	if (!game->images[GOAL] || !game->images[WALL] || !game->images[ITEM] || !game->images[PLAYER] || !game->images[FREE])
		my_close(game, "Error\n missing imagepath\n");
}
