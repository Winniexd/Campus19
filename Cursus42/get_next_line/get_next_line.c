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
#define BUFFER_SIZE 1
#endif

static char *prev_buffer;

char *get_next_line_helper(int ret, char *buffer, char *prev_buffer,
						   char *line)
{
	if (ret == 0)
	{
		free(buffer);
		free(prev_buffer);
		return (line);
	}
	free(prev_buffer);
	prev_buffer = ft_strdup(buffer);
	free(buffer);
	return (line);
}

char *get_next_line(int fd)
{
	char *line;
	char *buffer;
	int ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	line = malloc(sizeof(char) * BUFFER_SIZE);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret == -1 || ret == 0)
	{
		free(buffer);
		free(line);
		return (NULL);
	}
	if (buffer[0] == '\n')
	{
		free(buffer);
		free(prev_buffer);
		free(line);
		line = ft_strdup("");
		if (!line)
			return (NULL);
		return (line);
	}
	line[0] = '\0';
	if (prev_buffer && prev_buffer[0] != '\0')
		line = ft_strjoin(line, prev_buffer);
	while (ret > 0)
	{
		if (ft_strchr(buffer, '\n') || ft_strchr(buffer, '\0'))
		{
			line = ft_strjoin(line, buffer);
			free(prev_buffer);
			prev_buffer = NULL;
			return (get_next_line_helper(ret, buffer, prev_buffer, line));
		}
		line = ft_strjoin(line, buffer);
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	return (get_next_line_helper(ret, buffer, prev_buffer, line));
}
