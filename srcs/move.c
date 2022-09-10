/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:32:13 by kkai              #+#    #+#             */
/*   Updated: 2022/09/10 21:42:28 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void move_w(t_vars *game)
{
	int i;

	i = 0;
	while (i >= 0 && (size_t)i++ < ft_strlen(game->map_line))
	{
		if (game->map_line[i] == PLAYER)
			break;
	}
	if (game->map_line[i - game->width] == ITEM)
		game->itemNum--;
	if (game->map_line[i - game->width] == GOAL && game->itemNum <= 0)
		my_close(game, "Congraturations!!\n");
	else if (game->map_line[i - game->width] != WALL && game->map_line[i - game->width] != GOAL)
	{
		game->map_line[i] = FREE;
		game->map_line[i - game->width] = PLAYER;
		game->step_count++;
		printf("%d\n", game->step_count);
		set_map(game);
	}
}

void move_a(t_vars *game)
{
	int i;

	i = 0;
	while (i >= 0 && (size_t)i++ < ft_strlen(game->map_line))
	{
		if (game->map_line[i] == PLAYER)
			break;
	}
	if (game->map_line[i - game->width] == ITEM)
		game->itemNum--;
	if (game->map_line[i - game->width] == GOAL && game->itemNum <= 0)
		my_close(game, "Congraturations!!\n");
	else if (game->map_line[i - 1] != WALL && game->map_line[i - game->width] != GOAL)
	{
		game->map_line[i] = FREE;
		game->map_line[i - 1] = PLAYER;
		game->step_count++;
		printf("%d\n", game->step_count);
		set_map(game);
	}
}

void move_s(t_vars *game)
{
	int i;

	i = 0;
	while (i >= 0 && (size_t)i++ < ft_strlen(game->map_line))
	{
		if (game->map_line[i] == PLAYER)
			break;
	}
	if (game->map_line[i - game->width] == ITEM)
		game->itemNum--;
	if (game->map_line[i - game->width] == GOAL && game->itemNum <= 0)
		my_close(game, "Congraturations!!\n");
	else if (game->map_line[i + game->width] != WALL && game->map_line[i + game->width] != GOAL)
	{
		game->map_line[i] = FREE;
		game->map_line[i + game->width] = PLAYER;
		game->step_count++;
		printf("%d\n", game->step_count);
		set_map(game);
	}
}

void move_d(t_vars *game)
{
	int i;

	i = 0;
	while (i >= 0 && (size_t)i++ < ft_strlen(game->map_line))
	{
		if (game->map_line[i] == PLAYER)
			break;
	}
	if (game->map_line[i + 1] == ITEM)
		game->itemNum--;
	if (game->map_line[i + 1] == GOAL && game->itemNum <= 0)
		my_close(game, "Congraturations!!\n");
	else if (game->map_line[i + 1] != WALL && game->map_line[i + 1] != GOAL)
	{
		game->map_line[i] = FREE;
		game->map_line[i + 1] = PLAYER;
		game->step_count++;
		printf("%d\n", game->step_count);
		set_map(game);
	}
}
