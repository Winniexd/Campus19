/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:54:32 by matias            #+#    #+#             */
/*   Updated: 2024/10/01 14:27:50 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_config(t_config *c)
{
	int i;

	i = 0;
    if (c->file) 
	{
        while (c->file[i] != NULL)
		{
            free(c->file[i]);
			i++;
        }
        free(c->file);
    }
    if (c->fd >= 0)
        close(c->fd);
}

void free_map(t_map *m)
{
	int i;

	i = 0;
    if (m->map) 
	{
        while (m->map[i] != NULL)
		{
            free(m->map[i]);
			i++;
        }
        free(m->map);
    }
}

int	clean_exit(t_cub3d *c, int code)
{
	if (!c)
		exit(code);
	free_config(&c->config);
	free_map(&c->map);
	mlx_clear_window(c->mlx, c->win);
	mlx_destroy_window(c->mlx, c->win);
	mlx_destroy_display(c->mlx);
	mlx_loop_end(c->mlx);
	free(c->mlx);
	exit(1);
}
