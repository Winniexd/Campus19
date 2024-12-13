/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <jepatern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:22:25 by matias            #+#    #+#             */
/*   Updated: 2024/12/11 14:09:36 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	incorrect_value(int rgb)
{
	if (rgb >= 0 && rgb <= 255)
		return (false);
	return (true);
}

bool	arr_empty(char *str)
{
	int	i;
	int	is_empty;

	is_empty = true;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			is_empty = false;
		i++;
	}
	return (is_empty);
}

// Copy RGB values into in array in config struct
int	*cpy_rgb(char **arr)
{
	int	*rgb;
	int	i;

	rgb = malloc(3 * sizeof(int));
	if (!rgb)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		rgb[i] = ft_atoi(arr[i]);
		if (!rgb[i] || arr_empty(arr[i]) || incorrect_value(rgb[i]))
		{
			ft_free_arr(arr);
			free(rgb);
			return (NULL);
		}
		i++;
	}
	ft_free_arr(arr);
	return (rgb);
}

int	*cpy_color(char *line)
{
	char	**arr;
	int		*rgb;
	int		i;

	arr = ft_split(line, ',', 0);
	i = 0;
	while (arr[i])
		i++;
	if (i != 3)
	{
		ft_free_arr(arr);
		return (NULL);
	}
	rgb = cpy_rgb(arr);
	if (!rgb)
		return (NULL);
	return (rgb);
}

int	ft_fill_colors(t_config *config, char *line, int j)
{
	if (!line[j + 2])
		return (KO);
	if (line[j] == 'F' && !config->floor)
	{
		config->floor = cpy_color(line + j + 1);
		if (!config->floor)
			return (KO);
		config->floor_trgb = create_trgb(0, config->floor[0], config->floor[1],
				config->floor[2]);
	}
	if (line[j] == 'C' && !config->ceiling)
	{
		config->ceiling = cpy_color(line + j + 1);
		if (!config->ceiling)
			return (KO);
		config->ceiling_trgb = create_trgb(0, config->ceiling[0],
				config->ceiling[1], config->ceiling[2]);
	}
	return (OK);
}
