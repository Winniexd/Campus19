/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:49:07 by jepatern          #+#    #+#             */
/*   Updated: 2024/12/13 15:49:15 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	rotate_player(double *dirX, double *dirY, double angle)
{
	double	old_dirx;
	double	radians;

	old_dirx = *dirX;
	radians = ft_degrees_to_radians(angle);
	*dirX = old_dirx * cos(radians) - *dirY * sin(radians);
	*dirY = old_dirx * sin(radians) + *dirY * cos(radians);
}

void	ft_handle_movement(t_cub3d *comet, double *new_x,
		double *new_y)
{
	double	move_step;

	move_step = 0.10;
	if (comet->keys.forward)
	{
		*new_x -= comet->config.dir_xy[1] * move_step;
		*new_y += comet->config.dir_xy[0] * move_step;
	}
	else if (comet->keys.backward)
	{
		*new_x += comet->config.dir_xy[1] * move_step;
		*new_y -= comet->config.dir_xy[0] * move_step;
	}
	else if (comet->keys.left)
	{
		*new_x += comet->config.dir_xy[0] * move_step;
		*new_y += comet->config.dir_xy[1] * move_step;
	}
	else if (comet->keys.right)
	{
		*new_x -= comet->config.dir_xy[0] * move_step;
		*new_y -= comet->config.dir_xy[1] * move_step;
	}
}

void	ft_key_hook(t_cub3d *comet)
{
	double	new_x;
	double	new_y;

	new_x = comet->config.play_xy[0];
	new_y = comet->config.play_xy[1];
	ft_handle_movement(comet, &new_x, &new_y);
	if (comet->keys.rotate_left)
		rotate_player(&comet->config.dir_xy[0], &comet->config.dir_xy[1], -5);
	if (comet->keys.rotate_right)
		rotate_player(&comet->config.dir_xy[0], &comet->config.dir_xy[1], 5);
	if (ft_strchr("0NESW", comet->config.map[(int)new_y][(int)new_x]))
	{
		comet->config.play_xy[0] = new_x;
		comet->config.play_xy[1] = new_y;
	}
}
