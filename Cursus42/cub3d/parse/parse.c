/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:00:13 by matias            #+#    #+#             */
/*   Updated: 2024/09/08 21:54:35 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int *cpy_rgb(char **arr)
{
	int *rgb;
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

int	extract_data(t_cub3d *c, char **map, int i, int j)
{
	while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n')
		j++;
	if (!ft_ischar(map[i][j]))
	{
		if (map[i][j + 1] && !ft_ischar(map[i][j + 1]))
		{
			if (fill_directions(&c->config, map[i], j))
				return (KO);
			return (BREAK);
		}
		else
		{
			if (fill_colors(&c->config, map[i], j))
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
			{
				printf("Idk what's going on");
				return (KO);
			}
			else if (ret == OK)
				return (OK);
			j++;
		}
		i++;
	}
	return (OK);
}
