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
# define BUFFER_SIZE 1
#endif

char	*ft_line_read(char *start)
{
	int		i;
	char	*line;

	if (!start || !start[0])
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\n')
		i++;
	line = (char *)malloc(1 + i * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
	{
		line[i] = start[i];
		i++;
	}
	if (start[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_move_start(char *start)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\0')
	{
		free(start);
		return (NULL);
	}
	i += (start[i] == '\n');
	new_buff = (char *)malloc(1 + ft_strlen(start) - i);
	if (!new_buff)
		return (NULL);
	j = 0;
	while (start[i + j])
	{
		new_buff[j] = start[i + j];
		j++;
	}
	new_buff[j] = '\0';
	free(start);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			ret;
	static char	*start_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ret = 1;
	line = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!line)
		return (NULL);
	while (!(ft_strchr(start_line, '\n')) && ret != 0)
	{
		ret = read(fd, line, BUFFER_SIZE);
		if (ret == -1)
		{
			free(line);
			return (NULL);
		}
		line[ret] = '\0';
		start_line = ft_strjoin(start_line, line);
	}
	free(line);
	line = ft_line_read(start_line);
	start_line = ft_move_start(start_line);
	return (line);
}
