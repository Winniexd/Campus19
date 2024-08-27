/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:00:13 by matias            #+#    #+#             */
/*   Updated: 2024/08/27 10:50:06 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_data(t_cub3d *c, char **map, int i, int j)
{
	while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n')
		j++;
	if (!ft_ischar(map[i][j]))
	{
		if (map[i][j + 1] && !ft_ischar(map[i][j + 1]))
		{
			if (fill_directions(c->config, map[i], j))
				return (KO);
			return (BREAK);
		}
		else
		{
			if (fill_colors(c->config, map[i], j))
				return (KO);
			return (BREAK);
		}
	}
	return (CONTINUE);
}

int	parse_config(t_cub3d *c, char **map)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ret = extract_data(c, map, i, j);
			if (ret == BREAK)
				break ;
			else if (ret == KO)
				return (KO);
			else if (ret == OK)
				return (OK);
			j++;
		}
		i++;
	}
	return (OK);
}
