/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:04:18 by kkai              #+#    #+#             */
/*   Updated: 2022/09/10 17:07:21 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_mapjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (s1 == 0 && s2 == 0)
		return (NULL);
	else if (s1 == NULL)
		return ft_mapdup((char *)s2);
	else if (s2 == NULL)
		return ft_mapdup((char *)s1);
	else
	{
		p = (char *)ft_malloc(sizeof(char *), (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
		i = 0;
		while (s1[i] != '\n' && s1[i] != '\0')
			p[i] = s1[i];
		j = 0;
		while (s2[j] != '\n' && s2[j] != '\0')
			p[i++] = s2[j++];
		p[i] = '\0';
	}
	return (p);
}
