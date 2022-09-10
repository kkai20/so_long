/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:40:28 by kkai              #+#    #+#             */
/*   Updated: 2022/09/10 23:34:28 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <sys/types.h>
# include <sys/stat.h>
# include "get_next_line.h"
# include "mlx.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define GOAL_PATH "./images/goal.xpm"
# define WALL_PATH "./images/wall.xpm"
# define ITEM_PATH "./images/item.xpm"
# define PLAYER_PATH "./images/player.xpm"
# define FREE_PATH "./images/free.xpm"
# define TILE_SIZE 64

enum e_imags
{
	GOAL,
	WALL,
	ITEM,
	FREE,
	PLAYER,
	E_IMAGE_COUNT
};

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		player_x;
	int		player_y;
	int		itemNum;
	int		playerNum;
	int		goalNum;
	int		step_count;
	int		height;
	int		width;
	void	*images[E_IMAGE_COUNT];
	char	*map_filepath;
	char	*map_line;
}				t_vars;

void	make_window(t_vars *game);
void	init_images(t_vars *game);
void	set_map(t_vars *game);
void	read_map(t_vars *game);
int		check_key_code(int key_code, t_vars *game);
int		my_close(t_vars *game, char *message);
void	*ft_malloc(size_t number, size_t size);
void	count_map(t_vars *game);
char	*ft_mapdup(char *src);
char	*ft_mapjoin(char *s1, char *s2);
int		ft_open(char *filepath, int flags);
void	ft_close(int fd);
void	check_wall(t_vars *game);
void	move_w(t_vars *game_init);
void	move_a(t_vars *game_init);
void	move_s(t_vars *game_init);
void	move_d(t_vars *game_init);

#endif
