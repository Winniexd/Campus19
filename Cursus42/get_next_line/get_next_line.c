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

#define BUFFER_SIZE 1

char	*get_next_line_helper(int ret, char *buffer, char *prev_buffer,
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

char	*get_next_line(int fd)
{
	char		*line;
	static char	*prev_buffer;
	char		*buffer;
	int			ret;

	prev_buffer = malloc(sizeof(char) * BUFFER_SIZE);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	line = malloc(sizeof(char) * BUFFER_SIZE);
	line[0] = '\0';
	if (prev_buffer[0] != '\0')
		line = ft_strjoin(line, prev_buffer);
	ret = read(fd, buffer, BUFFER_SIZE);
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
