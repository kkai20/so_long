/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:57:45 by kkai              #+#    #+#             */
/*   Updated: 2022/09/10 10:34:49 by kkai             ###   ########.fr       */
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
