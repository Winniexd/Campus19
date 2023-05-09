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

char	*ft_parse(char *start)
{
	char	*end;
	size_t	len;
	char	*line;

	if (!start || !*start)
		return (NULL);
	end = ft_strchr(start, '\n');
	if (end != NULL)
		len = (size_t)(end - start + 1);
	else
		len = ft_strlen(start);
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	memcpy(line, start, len);
	line[len] = '\0';
	return (line);
}

char	*ft_move_start(char *start)
{
	int		i;
	char	*end;
	char	*new_buff;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\0')
	{
		free(start);
		return (NULL);
	}
	end = ft_strchr(start, '\n');
	if (!end)
	{
		free(start);
		return (NULL);
	}
	new_buff = strdup(end + 1);
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
	line = ft_parse(start_line);
	start_line = ft_move_start(start_line);
	return (line);
}
