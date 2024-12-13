/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bzero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <jepatern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:03:58 by matias            #+#    #+#             */
/*   Updated: 2024/12/12 17:22:03 by jepatern         ###   ########.fr       */
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
	c->config.width = 0;
	c->config.fd = 0;
}
