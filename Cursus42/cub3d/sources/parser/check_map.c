/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:05:35 by winniexd          #+#    #+#             */
/*   Updated: 2024/12/12 17:05:40 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	other_values_filled(t_config *config)
{
	if (!config->floor)
		return (KO);
	if (!config->ceiling)
		return (KO);
	if (!config->north)
		return (KO);
	if (!config->east)
		return (KO);
	if (!config->south)
		return (KO);
	if (!config->west)
		return (KO);
	return (OK);
}

int	check_valid_elements(char **map)
{
	int		i;
	int		j;
	bool	dir_filled;

	i = 0;
	dir_filled = false;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strrchr("NSEW01", map[i][j])
				&& !ft_is_white_char(map[i][j]))
				return (KO);
			if (ft_strrchr("NSEW", map[i][j]) && !dir_filled)
				dir_filled = true;
			else if (ft_strrchr("NSEW", map[i][j]) && dir_filled)
				return (KO);
			j++;
		}
		i++;
	}
	return (OK);
}

int	check_top_bottom(char **map, int row, int col)
{
	if (!map[row] || !map[row][col])
		return (KO);
	while (map[row][col])
	{
		if (map[row][col] != '1' && !ft_is_white_char(map[row][col]))
			return (KO);
		col++;
	}
	return (OK);
}

int	check_borders(t_config *config, char **map)
{
	int	row;
	int	col;

	if (check_top_bottom(map, 0, 0))
		return (KO);
	row = 1;
	while (row < config->height - 1)
	{
		col = 0;
		while (ft_is_white_char(map[row][col]))
			col++;
		if (map[row][col] != '1')
			return (KO);
		col = ft_strlen(map[row]) - 1;
		if (map[row][col] != '1')
			return (KO);
		row++;
	}
	if (check_top_bottom(map, row, 0))
		return (KO);
	return (OK);
}

int	check_map(t_config *config)
{
	if (!config->map)
		return (ft_write_err(MAP_ERR, "No map allocated"));
	if (check_borders(config, config->map))
		return (ft_write_err(MAP_ERR, "Error with borders"));
	if (config->height < 3)
		return (ft_write_err(MAP_ERR, "Map too small"));
	if (check_valid_elements(config->map))
		return (ft_write_err(MAP_ERR, "Invalid element(s)"));
	if (other_values_filled(config))
		return (ft_write_err(MAP_ERR, "Values missing"));
	return (OK);
}
