/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:27:04 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/28 15:52:37 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_cub3d *c)
{
	c->mlx = mlx_init();
	c->win = mlx_new_window(c->mlx, WIDTH, HEIGHT, "Cub3D");
}

int find_value(char *line)
{
	char **str;

	str = ft_split(line, ',');
	printf("%s", str[0]);
	return 1;
}

void init_config(t_config *config)
{
	int i;

	i = 0;
	while (i < 6)
		config->data[i++] = 0;
}

int find_key(char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		return NO;
	if (line[0] == 'E' && line[1] == 'E')
		return EA;
	if (line[0] == 'S' && line[1] == 'O')
		return SO;
	if (line[0] == 'W' && line[1] == 'E')
		return WE;
	if (line[0] == 'F' && line[1] == ' ')
		return F;
	if (line[0] == 'C' && line[1] == ' ')
		return C;
	return 6;
}

int parse_line(char *line, t_cub3d *c)
{
	int key;

	key = find_key(line);
	c->config.data[key] = find_value(line);
	return 0;
}

void	init_map(t_cub3d *c, char *path)
{
	int		fd;
	char	*line;

	init_config(&c->config);
	if (ft_suffix(path, ".cub"))
		free_mlx(c);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		free_mlx(c);
	line = get_next_line(fd);
	while (line)
	{
		if (parse_line(line, c))
			return;
		free(line);
		line = get_next_line(fd);
	}
}
