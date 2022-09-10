/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:04:18 by kkai              #+#    #+#             */
/*   Updated: 2022/09/10 23:36:44 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strlcpy(char *dst, char *src, int len)
{
	int src_len;
	int i;

	src_len = 0;
	i = 0;
	while (src[src_len] !='\0')
		src_len++;
	if (len == 0)
	{
		return (src_len);
	}
	while (i < len - 1 && src[i] != '\0' && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char *ft_mapjoin(char *s1, char *s2)
{
	char	*heap;
	int		s1_len;
	int		s2_len;

	if (s1 == 0 && s2 == 0)
		return (NULL);
	else if (s1 == NULL)
		return ft_mapdup((char *)s2);
	else if (s2 == NULL)
		return ft_mapdup((char *)s1);
	s1_len = (int)ft_strlen(s1);
	s2_len = (int)ft_strlen(s2);
	heap = (char *)ft_malloc(sizeof(char *), (s1_len + s2_len));
	ft_strlcpy(heap, s1, s1_len + 1);
	ft_strlcpy(heap + s1_len, s2, s2_len + 1);
	free(s1);
	free(s2);
	return (heap);
}
