/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:17:20 by matias            #+#    #+#             */
/*   Updated: 2024/09/09 10:21:50 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_path(char *line, int j)
{
	int		len;
	char	*path;
	int		i;

	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	len = j;
	while (line[len] && (line[len] != '\n'))
		len++;
	path = malloc((len - j + 1) * sizeof(char));
	if (!path)
		return (NULL);
	i = 0;
	while (j < len)
		path[i++] = line[j++];
	path[i] = '\0';
	return (path);
}
