/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bzero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:03:58 by matias            #+#    #+#             */
/*   Updated: 2024/11/14 17:39:17 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// We initialize some variables to NULL to avoid some undefined behavior
// Also to avoid garbage values

void	struct_bzero(t_cub3d *c)
{
	c->mlx = NULL;
	c->config.north = NULL;
	c->config.east = NULL;
	c->config.south = NULL;
	c->config.west = NULL;
	c->config.ceiling = NULL;
	c->config.floor = NULL;
	c->config.file = NULL;
	c->config.map = NULL;
	c->config.dir_xy[0] = 0.00;
	c->config.dir_xy[1] = 0.00;
	c->config.height = 0;
}
