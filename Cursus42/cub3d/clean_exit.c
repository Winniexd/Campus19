/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:54:32 by matias            #+#    #+#             */
/*   Updated: 2024/08/27 10:40:54 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	clean_exit(t_cub3d *c, int code)
{
	if (!c)
		exit(code);
	mlx_clear_window(c->mlx, c->win);
	mlx_destroy_window(c->mlx, c->win);
	mlx_destroy_display(c->mlx);
	mlx_loop_end(c->mlx);
	free(c->mlx);
	exit(1);
}
