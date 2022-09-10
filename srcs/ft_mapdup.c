/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:40:37 by kkai              #+#    #+#             */
/*   Updated: 2022/09/10 23:04:34 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_mapdup(char *src)
{
	size_t	num;
	char	*dest;

	num = ft_strlen(src);
	dest = (char *)ft_malloc(sizeof(char *), (num + 1));
	num = 0;
	while (src[num] != '\n' && src[num] != '\0')
	{
		dest[num] = src[num];
		num++;
	}
	dest[num] = '\0';
	return (dest);
}
