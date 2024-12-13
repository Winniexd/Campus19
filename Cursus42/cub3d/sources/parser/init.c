/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <jepatern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:32:41 by matias            #+#    #+#             */
/*   Updated: 2024/12/12 17:15:16 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(t_cub3d *c)
{
	c->mlx = mlx_init();
	if (!c->mlx)
		ft_clean_exit(c, 1);
	c->win = mlx_new_window(c->mlx, WIDTH, HEIGHT, "Cub3d");
	if (!c->win)
		ft_clean_exit(c, 1);
}

int	ft_init_textures(t_cub3d *c, t_config *config)
{
	if (ft_parse_xpm(&(c->img[NO]), config->north)
		|| ft_parse_xpm(&(c->img[EA]), config->east)
		|| ft_parse_xpm(&(c->img[SO]), config->south)
		|| ft_parse_xpm(&(c->img[WE]), config->west))
		return (KO);
	return (OK);
}

int	check_file(char *path, int is_cub)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_write_err("Unable to open file", path));
	close(fd);
	if (is_cub && ft_suffix(path, ".cub"))
		return (ft_write_err("Invalid cub file", path));
	if (!is_cub && ft_suffix(path, ".xpm"))
		return (ft_write_err("Invalid xpm file", path));
	return (0);
}

// Copy contents from file into config->file for parsing later on
int	copy_file(t_config *config, char *path)
{
	int		line_count;
	char	*line;
	int		i;

	line_count = ft_get_line_count(path);
	config->file = malloc((line_count + 1) * sizeof(char *));
	if (!(config->file))
		return (ft_write_err(MALLOC_ERR, NULL));
	config->fd = open(path, O_RDONLY);
	line = get_next_line(config->fd);
	i = 0;
	while (line)
	{
		config->file[i] = ft_strdup(line, 1);
		i++;
		line = get_next_line(config->fd);
	}
	config->file[i] = NULL;
	close(config->fd);
	return (0);
}

int	ft_init_cub3d(t_cub3d *c, char *path)
{
	struct_bzero(c);
	if (check_file(path, 1) || copy_file(&c->config, path))
		ft_clean_exit(c, 1);
	if (ft_parse_config(c, c->config.file) || check_map(&c->config)
		|| ft_init_textures(c, &c->config))
		ft_clean_exit(c, 2);
	return (0);
}
