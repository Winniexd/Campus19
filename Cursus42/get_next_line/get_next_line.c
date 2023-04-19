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
#define BUFFER_SIZE 10
#endif

char *get_next_line_helper(int ret, char *buffer, char *prev_buffer,
						   char *line)
{
	if (ret == 0)
	{
		free(buffer);
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
	static char *prev_buffer = NULL;
	char *buffer;
	int ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (prev_buffer == NULL)
		prev_buffer = malloc(sizeof(char) * BUFFER_SIZE);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer || !prev_buffer)
		return (NULL);
	line = malloc(sizeof(char) * BUFFER_SIZE);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (prev_buffer[0] != '\0')
		line = ft_strjoin(line, prev_buffer);
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret == -1)
	{
		free(buffer);
		free(prev_buffer);
		free(line);
		return (NULL);
	}
	while (ret > 0)
	{
		if (ft_strchr(buffer, '\n'))
		{
			line = ft_strjoin(line, buffer);
			free(prev_buffer);
			prev_buffer = NULL;
			return (line);
		}
		line = ft_strjoin(line, buffer);
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	return (get_next_line_helper(ret, buffer, prev_buffer, line));
}
