/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:32:41 by matias            #+#    #+#             */
/*   Updated: 2024/09/07 12:29:27 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_cub3d *c)
{
	c->mlx = mlx_init();
	if (!c->mlx)
		clean_exit(c, 1);
	c->win = mlx_new_window(c->mlx, WIDTH, HEIGHT, "Cub3d");
	if (!c->win)
		clean_exit(c, 1);
}

int	check_file(char *path, int is_cub)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (write_err("Error\nInvalid file\n", 1));
	close(fd);
	if (is_cub && ft_suffix(path, ".cub"))
		return (write_err("Error\nInvalid cub file\n", 1));
	if (!is_cub && ft_suffix(path, ".xpm"))
		return (write_err("Error\nInvalid xpm file\n", 1));
	return (0);
}

int	copy_file(t_cub3d *c, char *path)
{
	int		line_count;
	char	*line;
	int		i;

	line_count = get_line_count(path);
	c->map.map = malloc((line_count + 1) * sizeof(char *));
	if (!(c->map.map))
		clean_exit(c, 1);
	c->config.fd = open(path, O_RDONLY);
	line = get_next_line(c->config.fd);
	i = 0;
	while (line)
	{
		c->map.map[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(c->config.fd);
	}
	close(c->config.fd);
	return (0);
}

int	init_cub3d(t_cub3d *c, char *path)
{
	struct_bzero(c);
	if (check_file(path, 1) || copy_file(c, path))
		clean_exit(c, 1);
	if (parse_config(c, c->map.map))
		clean_exit(c, 2);
	return (0);
}
