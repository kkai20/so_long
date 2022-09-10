/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:47:51 by kkai              #+#    #+#             */
/*   Updated: 2022/09/10 13:33:57 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strdup_without_newline(char *line)
{
	char	*heap;
	int		size;
	int		i;

	heap = NULL;
	size = ft_strlen(line);
	i = 0;
	heap = (char *)ft_malloc(sizeof(char *), size + 1);
	while

}
