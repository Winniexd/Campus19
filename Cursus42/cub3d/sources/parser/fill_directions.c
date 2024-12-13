/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <jepatern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:23:58 by matias            #+#    #+#             */
/*   Updated: 2024/12/12 17:09:12 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Copy path strings into the config struct
int	ft_fill_directions(t_config *config, char *line, int j)
{
	char	*path;

	path = ft_get_path(line + 2, j);
	if (!line[j + 2])
		return (KO);
	if (check_file(path, 0))
	{
		free(path);
		return (KO);
	}
	free(path);
	if (line[j] == 'N' && line[j + 1] == 'O' && !config->north)
		config->north = ft_get_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !config->east)
		config->east = ft_get_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !config->south)
		config->south = ft_get_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !config->west)
		config->west = ft_get_path(line, j + 2);
	else
		return (KO);
	return (OK);
}
