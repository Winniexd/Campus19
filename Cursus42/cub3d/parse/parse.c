/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:00:13 by matias            #+#    #+#             */
/*   Updated: 2024/10/01 14:24:38 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_data(t_cub3d *c, char **buffer, int i, int j)
{
	while (buffer[i][j] == ' ' || buffer[i][j] == '\t' || buffer[i][j] == '\n')
		j++;
	if (!ft_ischar(buffer[i][j]))
	{
		if (buffer[i][j + 1] && !ft_ischar(buffer[i][j + 1]))
		{
			if (fill_directions(&c->config, buffer[i], j))
				return (KO);
			return (BREAK);
		}
		else
		{
			if (fill_colors(&c->config, buffer[i], j))
				return (KO);
			return (BREAK);
		}
	}
	else if (!ft_isdigit(buffer[i][j]))
	{
		if (fill_map(&c->map, buffer, i))
			return (KO);
		return (OK);
	}
	return (CONTINUE);
}

int	parse_config(t_cub3d *c, char **buffer)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j])
		{
			ret = extract_data(c, buffer, i, j);
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
