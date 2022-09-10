/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:57:13 by kkai              #+#    #+#             */
/*   Updated: 2022/09/10 22:45:10 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_key_code(int key_code, t_vars *game)
{
	if (key_code == KEY_ESC)
		my_close(game, "");
	else if (key_code == KEY_W)
		move_w(game);
	else if (key_code == KEY_S)
		move_s(game);
	else if (key_code == KEY_A)
		move_a(game);
	else if (key_code == KEY_D)
		move_d(game);
	return (0);
}
