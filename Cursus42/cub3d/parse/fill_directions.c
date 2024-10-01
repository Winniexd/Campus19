/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:23:58 by matias            #+#    #+#             */
/*   Updated: 2024/09/09 10:24:19 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fill_directions(t_config *config, char *line, int j)
{
	if (!line[j + 2])
		return (KO);
	if (line[j] == 'N' && line[j + 1] == 'O' && !config->north)
		config->north = get_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !config->east)
		config->east = get_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !config->south)
		config->south = get_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !config->west)
		config->west = get_path(line, j + 2);
	else
		return (KO);
	return (OK);
}
