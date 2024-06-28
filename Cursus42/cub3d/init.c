/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:27:04 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/28 11:46:07 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_cub3d *c)
{
	c->mlx = mlx_init();
	c->win = mlx_new_window(c->mlx, WIDTH, HEIGHT, "Cub3D");
}

void	init_map(t_cub3d *c, char *path)
{
	int		fd;
	int		ret;
	char	*line;

	if (ft_suffix(path, ".cub"))
		free_mlx(c);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		free_mlx(c);
	line = get_next_line(fd);
	while (line)
	{
		if (parse_line)
			free_mlx(c);
		line = get_next_line(fd);
	}
}
