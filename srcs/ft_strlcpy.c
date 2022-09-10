/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:22:26 by kkai              #+#    #+#             */
/*   Updated: 2022/09/10 16:18:13 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	n;
	size_t	size;

	size =ft_strlen((char *)src);
	n = 0;
	if (destsize != 0)
	{
		while (n < destsize - 1 && src[n] != '\0')
		{
			dest[n] = src[n];
			n++;
		}
		dest[n] = '\0';
	}
	return (size);
}
