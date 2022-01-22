/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:57:52 by kkai              #+#    #+#             */
/*   Updated: 2022/01/22 18:28:24 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*ft_buffcat(char *heap, char *buff, size_t n_add)
{
	size_t	heap_len;
	size_t	i;

	heap_len = ft_strlen(heap);
	i = 0;
	while (i < n_add)
		heap[heap_len++] = buff[i++];
	heap[heap_len] = '\0';
	return (heap);
}

char	*ft_strjoin(char *line, char *buff, size_t n_add)
{
	char	*heap;

	if (line == NULL || buff == NULL)
		return (NULL);
	heap = (char *)malloc(ft_strlen(line) + n_add + 2);
	if (heap == NULL)
		return (NULL);
	heap = ft_strcpy(heap, line);
	heap = ft_buffcat(heap, buff, n_add);
	return (heap);
}

char	*ft_strdup(char *src)
{
	char	*heap;
	size_t	i;

	i = ft_strlen(src);
	heap = (char *)malloc(sizeof(char) * (i + 1));
	if (heap == NULL)
		return (NULL);
	heap = ft_strcpy(heap, src);
	return (heap);
}
