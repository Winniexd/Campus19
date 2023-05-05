/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:45:00 by mdreesen          #+#    #+#             */
/*   Updated: 2023/04/13 14:59:01 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

void *ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;

	str = (unsigned char *)b;
	while (len--)
	{
		*str = (unsigned char)c;
		if (len)
			str++;
	}
	return (b);
}

void ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

char *ft_read_line(char *buff, char **prev_buff)
{
	char *line;
	char *temp;
	int i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n')
	{
		line = ft_substr(buff, 0, i + 1);
		temp = ft_strdup(&buff[i + 1]);
		ft_free(prev_buff);
		*prev_buff = temp;
	}
	else
	{
		line = ft_strdup(buff);
		ft_free(prev_buff);
	}
	return (line);
}

char *get_next_line(int fd)
{
	static char *prev_buff;
	char *buff;
	char *line;
	int ret;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ret = read(fd, buff, BUFFER_SIZE);
	if (fd < 0 || ret < 0 || BUFFER_SIZE < 1)
	{
		ft_free(&buff);
		return (NULL);
	}
	if (ret == 0 && !prev_buff)
	{
		ft_free(&buff);
		return (NULL);
	}
	while (ret > 0)
	{
		line = ft_read_line(buff, &prev_buff);
		if (ft_strchr(buff, '\n'))
			break;
		ret = read(fd, buff, BUFFER_SIZE);
	}
	ft_memset(&buff, 0, BUFFER_SIZE + 1);
	if (ret == 0 && !prev_buff)
		return (NULL);
	return (line);
}