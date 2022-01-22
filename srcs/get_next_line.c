/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:58:05 by kkai              #+#    #+#             */
/*   Updated: 2022/01/21 17:58:54 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_malloc(char **line, char **buff, int *flag)
{
	*flag = 0;
	*line = (char *)malloc(1);
	if (*line == NULL)
		return (-1);
	*line[0] = '\0';
	*buff = (char *)malloc(BUFFER_SIZE + 1);
	if (*buff == NULL)
	{
		free(*line);
		return (-1);
	}
	return (1);
}

static size_t	ft_strchr(char *buff, char c)
{
	size_t	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static int	ft_put_line(char **line, char **memo, char *buff)
{
	int		flag;
	size_t	n_add;
	char	*tmp;

	n_add = ft_strchr(buff, '\n');
	tmp = ft_strjoin(*line, buff, n_add);
	if (tmp == NULL)
		return (-1);
	free(*line);
	*line = tmp;
	tmp = NULL;
	flag = 0;
	if (buff[n_add] == '\n')
	{
		tmp = ft_strdup(&buff[n_add + 1]);
		if (tmp == NULL)
			return (-1);
		flag = 1;
	}
	free(*memo);
	*memo = tmp;
	tmp = NULL;
	return (flag);
}

static void	ft_free_buff(int flag, char **buff, char **memo, char **line)
{
	free(*buff);
	*buff = NULL;
	if (flag == -1)
	{
		free(*memo);
		*memo = NULL;
		free(*line);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*memo[256];
	char		*buff;
	int			flag;
	ssize_t		n;

	if (fd < 0 || 256 <= fd || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (ft_malloc(line, &buff, &flag) == -1)
		return (-1);
	if (memo[fd])
		flag = ft_put_line(line, &memo[fd], memo[fd]);
	n = 0;
	if (flag == 0)
		n = read(fd, buff, BUFFER_SIZE);
	while (n > 0 && flag == 0)
	{
		buff[n] = '\0';
		flag = ft_put_line(line, &memo[fd], buff);
		if (flag == 0)
			n = read(fd, buff, BUFFER_SIZE);
	}
	ft_free_buff(flag, &buff, &memo[fd], line);
	if (n == -1)
		return (-1);
	return (flag);
}
