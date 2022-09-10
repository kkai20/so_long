/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:57:45 by kkai              #+#    #+#             */
/*   Updated: 2022/09/10 18:08:56 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_malloc(size_t byte, size_t size)
{
	void	*heap;

	heap = malloc(byte * size);
	if (heap == NULL)
	{
		perror("malloc error\n");
		exit(EXIT_FAILURE);
	}
	return (heap);
}

int		ft_open(char *filepath, int flags)
{
	int	fd;

	fd = open(filepath, flags);
	if (fd == -1)
		perror("Error\n Can't open file.\n");
	return (fd);
}

void	ft_close(int fd)
{
	if (close(fd) == -1)
		perror("Error\n Can't close file.\n");
}
