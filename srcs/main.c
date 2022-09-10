/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:58:37 by kkai              #+#    #+#             */
/*   Updated: 2022/09/10 22:46:02 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	my_close(t_vars *game, char *message)
{
	int	i;

	if (game->mlx)
	{
		if (game->win)
		{
			printf("destry");
			mlx_destroy_window(game->mlx, game->win);
		}
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


void	check_map(t_vars *game)
{
	int	i;

	if (game->itemNum <= 0)
	{
		printf("ITEM\n");
		my_close(game, "Error\n missing item\n");
	}
	if (game->playerNum != 1)
	{
		printf("Play\n");
		my_close(game, "Error\n player must be only one\n");
	}
	if (game->goalNum <= 0)
	{
		printf("GOAL\n");
		my_close(game, "Error\n missing goal\n");
	}
	i = game->height * game->width;
	if (i > 0 && (size_t)i != ft_strlen(game->map_line))
	{
		printf("RECTUNGLE\n");
		my_close(game, "Error\n map is not rectangular.\n");
	}
	check_wall(game);
}

void	game_init(t_vars *game, char *argv)
{
	game->map_filepath = argv;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		my_close(game, "Error\n malloc error\n");
	init_images(game);
	read_map(game);
	make_window(game);
	count_map(game);
	check_map(game);
	set_map(game);
}

void	register_hooks(t_vars *game)
{
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 1, &check_key_code, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 1, &simple_close, game);
	// mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_vars	*game;

	if (argc != 2)
		simple_exit("Error\n illegal arguments\n");
	game = (t_vars *)ft_malloc(sizeof(t_vars), 1);
	game_init(game, argv[1]);
	register_hooks(game);
}
