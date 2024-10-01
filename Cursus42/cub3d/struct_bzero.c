/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bzero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:03:58 by matias            #+#    #+#             */
/*   Updated: 2024/09/30 14:42:54 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	struct_bzero(t_cub3d *c)
{
	c->config.north = NULL;
	c->config.east = NULL;
	c->config.south = NULL;
	c->config.west = NULL;
	c->config.ceiling = NULL;
	c->config.floor = NULL;
	c->config.file = NULL;
	c->map.map = NULL;
}