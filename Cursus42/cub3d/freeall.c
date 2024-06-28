/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:36:27 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/28 13:51:35 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_mlx(t_cub3d *c)
{
	mlx_clear_window(c->mlx, c->win);
	mlx_destroy_window(c->mlx, c->win);
	mlx_destroy_display(c->mlx);
	mlx_loop_end(c->mlx);
	free(c->mlx);
	free(c);
	exit(0);
}
