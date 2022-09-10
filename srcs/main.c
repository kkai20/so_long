/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:58:37 by kkai              #+#    #+#             */
/*   Updated: 2022/09/10 16:38:51 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	my_close(t_vars *game, char *message)
{
	int	i;

	if (game->mlx)
	{
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		i = -1;
		while (++i < 5)
		{
			if (game->images[i])
				mlx_destroy_image(game->mlx, game->images[i]);
		}
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	i = -1;
	if (game->map)
	{
		while (game->map[++i])
			free(game->map[i]);
		free(game->map);
	}
	perror(message);
	free(game);
	exit(EXIT_FAILURE);
}

int	simple_close(t_vars *game)
{
	my_close(game, "");
	exit(EXIT_FAILURE);
}

int	simple_exit(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	add_game_value(t_vars *game, char *argv)
{
	game->map_filepath = argv;
	get_map_size(game);
	game->map = (int **)ft_malloc(sizeof(int *), game->height + 1);
}

void	check_map(t_vars *game)
{
	if (game->itemNum <= 0)
		my_close(game, "Error\n missing item\n");
	if (game->playerNum != 1)
		my_close(game, "Error\n player must be only one\n");
	if (game->goalNum <= 0)
		my_close(game, "Error\n missing goal\n");
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

	game = (t_vars *)ft_malloc(sizeof(t_vars), 1);
	if (argc != 2)
		my_close(game, "Error\n illegal arguments\n");
	add_game_value(game, argv[1]);
	i = 0;
	while (i < game->height)
	{
		//game->map[i] = (int *)ft_malloc(sizeof(int), game->wid + 1);
		game->map[i] = (int *)ft_malloc(sizeof(int), game->width);

		if (game->map[i] == NULL)
			simple_exit("Error\n malloc error\n");
		i++;
	}
	read_map(game);
	count_map(game);
	check_map(game);
	make_window(game);
	init_images(game);
	register_hooks(game);
}
