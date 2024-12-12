/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:26:57 by matias            #+#    #+#             */
/*   Updated: 2024/12/12 17:18:54 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_direction(char c, t_config *config)
{
	if (c == 'N')
		config->dir_xy[1] = 1.00;
	if (c == 'E')
		config->dir_xy[0] = 1.00;
	if (c == 'S')
		config->dir_xy[1] = -1.00;
	if (c == 'W')
		config->dir_xy[0] = -1.00;
}

int	get_player_pos(t_config *config)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = config->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S'
				|| map[i][j] == 'W')
			{
				config->play_xy[0] = j;
				config->play_xy[1] = i;
				get_direction(map[i][j], config);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

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
		while (map[i][j] && ft_is_white_char(map[i][j]))
			j++;
		if (map[i][j] == '\n')
			break ;
		if (map[i][j] != '1')
			return (ft_write_err("Left wall element is not '1'", NULL));
		i++;
	}
	return (i - tmp);
}

// Copy the map into the map array
void	copy_row(char *dst, char *src)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (src[j] && src[j] != '\n')
	{
		dst[k++] = src[j++];
	}
	dst[k] = '\0';
}

int	ft_fill_map(t_cub3d *c, char **buffer, int i)
{
	int	row;

	c->config.height = get_map_height(buffer, i);
	c->config.map = malloc(sizeof(char *) * (c->config.height + 1));
	row = 0;
	if (!c->config.map)
		return (ft_write_err(MALLOC_ERR, NULL));
	while (buffer[i] && row < c->config.height)
	{
		c->config.map[row] = malloc(sizeof(char) * (ft_strlen(buffer[i]) + 1));
		if (!c->config.map[row])
			return (ft_write_err(MALLOC_ERR, NULL));
		copy_row(c->config.map[row], buffer[i]);
		i++;
		row++;
	}
	c->config.map[row] = NULL;
	if (get_player_pos(&c->config))
		return (ft_write_err("No player found", NULL));
	return (OK);
}
