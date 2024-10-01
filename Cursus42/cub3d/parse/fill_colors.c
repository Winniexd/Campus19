/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:22:25 by matias            #+#    #+#             */
/*   Updated: 2024/09/09 10:22:53 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*cpy_rgb(char **arr)
{
	int	*rgb;
	int	i;

	rgb = malloc(3 * sizeof(int));
	if (!rgb)
		return (0);
	i = 0;
	while (arr[i])
	{
		rgb[i] = ft_atoi(arr[i]);
		if (!rgb[i])
		{
			free_arr(arr);
			free(rgb);
			return (0);
		}
		i++;
	}
	return (rgb);
}

int	*cpy_color(char *line)
{
	char	**arr;
	int		*rgb;
	int		i;

	arr = ft_split(line, ',');
	i = 0;
	while (arr[i])
		i++;
	if (i != 3)
	{
		free_arr(arr);
		return (0);
	}
	rgb = cpy_rgb(arr);
	if (!rgb)
		return (0);
	return (rgb);
}

int	fill_colors(t_config *config, char *line, int j)
{
	if (!line[j + 2])
		return (KO);
	if (line[j] == 'F' && !config->floor)
	{
		config->floor = cpy_color(line + j + 1);
		if (!config->floor)
			return (KO);
	}
	if (line[j] == 'C' && !config->ceiling)
	{
		config->ceiling = cpy_color(line + j + 1);
		if (!config->ceiling)
			return (KO);
	}
	return (OK);
}
