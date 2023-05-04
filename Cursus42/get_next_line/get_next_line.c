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
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4
#endif

void ft_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

char *get_next_line(int fd)
{
	static char *prev_buffer;
	char *buffer;
	char *line;
	int ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret == -1 || !buffer || ret == 0)
	{
		ft_free(buffer);
		return (NULL);
	}
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (prev_buffer)
		{
			line = ft_strjoin(prev_buffer, buffer);
			ft_free(prev_buffer);
			prev_buffer = NULL;
		}
		else
			line = ft_strdup(buffer);
		if (ret == 0 || ret <= BUFFER_SIZE)
		{
			ft_free(buffer);
			return (line);
		}
		if (ft_strchr(line, '\n'))
		{
			prev_buffer = ft_strdup(ft_strchr(line, '\n') + 1);
			*(ft_strchr(line, '\n')) = '\0';
			ft_free(buffer);
			return (line);
		}
		ret = read(fd, buffer, BUFFER_SIZE);
		ft_free(line);
	}
	ft_free(buffer);
	return (NULL);
}