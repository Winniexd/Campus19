/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:26:57 by matias            #+#    #+#             */
/*   Updated: 2024/10/01 14:26:52 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map_height(char **map, int i)
{
	int	j;
	int	tmp;

	if (!map || !map[i])
		return (0);
	tmp = i;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && !is_white_char(map[i][j]))
			j++;
		if (map[i][j] != '1')
			break ;
		i++;
	}
	return (i - tmp);
}

int	fill_map(t_map *m, char **buffer, int i)
{
	int	j;
	int	row;

	m->height = get_map_height(buffer, i);
	m->map = malloc(sizeof(char *) * (m->height + 1));
	row = 0;
	if (!m->map)
		return (KO);
	while (buffer[i])
	{
		j = 0;
		m->map[row] = malloc(ft_strlen(buffer[i]) + 1);
		if (!m->map[row])
			return (KO);
		while (buffer[i][j])
		{
			m->map[row][j] = buffer[i][j];
			j++;
		}
		m->map[row][j] = '\0';
		i++;
		row++;
	}
	m->map[row] = NULL;
	return (OK);
}
