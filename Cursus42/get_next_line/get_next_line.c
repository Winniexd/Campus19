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



char *get_next_line_helper(int ret, char *buffer, char *prev_buffer, char *line)
{
    free(prev_buffer);

    if (ret != 0)
    {
        prev_buffer = ft_strdup(buffer);
    }

    free(buffer);
    return (line);
}

char	*get_next_line(int fd)
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
	ret = 1;
	while (ret != 0 && !ft_strchr(prev_buffer, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buffer[ret] = '\0';
		prev_buffer = ft_strjoin(prev_buffer, buffer);
	}
	line = ft_substr(prev_buffer, 0, ft_strchr(prev_buffer, '\n') - prev_buffer);
	prev_buffer = ft_substr(prev_buffer, ft_strchr(prev_buffer, '\n') - prev_buffer + 1, ft_strlen(prev_buffer));
	return (get_next_line_helper(ret, buffer, prev_buffer, line));
}