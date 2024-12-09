/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <jepatern@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:22:48 by jepatern          #+#    #+#             */
/*   Updated: 2024/05/02 15:42:52 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*ft_get_save_and_str(char **str)
{
	int		i;
	char	*save;
	char	*new_str;

	i = 0;
	while (str[0][i] && str[0][i] != '\n')
		i++;
	save = ft_strdup(&str[0][++i], 0);
	str[0][i] = '\0';
	new_str = ft_strdup(str[0], 1);
	str[0] = new_str;
	return (save);
}

char	*ft_gnl(char **str, int fd, char *buffer)
{
	int		x;

	x = -1;
	while (ft_there_is_c(*str, '\n') == 0)
	{
		if (buffer)
			x = read(fd, buffer, BUFFER_SIZE);
		if (x <= 0 || !buffer)
		{
			if (x < 0 && *str)
			{
				ft_free(&*str);
				*str = NULL;
			}
			if (buffer)
				ft_free(&buffer);
			return (NULL);
		}
		buffer[x] = '\0';
		*str = ft_strjoin_gnl(*str, buffer);
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	}
	free (buffer);
	return (ft_get_save_and_str(str));
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*str;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (save[fd] && save[fd][0])
	{
		str = ft_strjoin_gnl(str, save[fd]);
		if (ft_there_is_c(str, '\n'))
		{
			save[fd] = ft_get_save_and_str(&str);
			return (str);
		}
	}
	save[fd] = ft_gnl(&str, fd, malloc(sizeof(char) * (BUFFER_SIZE + 1)));
	return (str);
}
