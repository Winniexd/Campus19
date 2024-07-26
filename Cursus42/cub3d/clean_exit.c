/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:54:32 by matias            #+#    #+#             */
/*   Updated: 2024/07/26 14:50:49 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	clean_exit(t_cub3d *c, int code)
{
	if (!c)
		exit(code);
	if (&c->map.map)
		free(&c->map.map);
	mlx_clear_window(c->mlx, c->win);
	mlx_destroy_window(c->mlx, c->win);
	mlx_destroy_display(c->mlx);
	mlx_loop_end(c->mlx);
	free(c->mlx);
	exit(1);
}