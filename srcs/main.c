/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:58:37 by kkai              #+#    #+#             */
/*   Updated: 2022/01/22 19:40:17 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_close(t_vars *game, char *message)
{
	int	i;

	i = -1;
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
	{
		while (game->map[++i])
			free(game->map[++i]);
		free(game->map);
	}
	printf("%s", message);
	exit(0);
}

int	simple_close(t_vars *game)
{
	my_close(game, "");
	exit(0);
}

void	check_map(t_vars *game)
{
	if (game->itemNum <= 0)
		my_close(game, "Error: too few items\n");
	if (game->playerNum != 1)
		my_close(game, "Error: player must be only one\n");
	if (game->goalNum <= 0)
		my_close(game, "Error: too many goals\n");
}

void	register_hooks(t_vars *game)
{
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 1, &deal_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 1, &simple_close, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_vars	*game;
	int		i;

	game = (t_vars *)ft_calloc(sizeof(t_vars), 1);
	if (argc != 2)
		my_close(game, "illegal arguments");
	game->map_filepath = argv[1];
	game->key_flag = 1;
	get_map_size(game);
	game->map = (int **)ft_calloc(sizeof(int *), game->rows + 1);
	i = 0;
	while (i < game->rows)
	{
		game->map[i] = (int *)ft_calloc(sizeof(int), game->cols + 1);
		i++;
	}
	read_map(game);
	count_map(game);
	check_map(game);
	make_window(game);
	init_images(game);
	register_hooks(game);
}
