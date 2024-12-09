/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:43:39 by winniexd          #+#    #+#             */
/*   Updated: 2024/12/04 11:43:40 by winniexd         ###   ########.fr       */
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

void	ft_handle_movement(int key, t_cub3d *comet, double *new_x,
		double *new_y)
{
	double	move_step;

	move_step = 0.10;
	if (key == 100)
	{
		*new_x -= comet->config.dir_xy[1] * move_step;
		*new_y += comet->config.dir_xy[0] * move_step;
	}
	else if (key == 97)
	{
		*new_x += comet->config.dir_xy[1] * move_step;
		*new_y -= comet->config.dir_xy[0] * move_step;
	}
	else if (key == 119)
	{
		*new_x += comet->config.dir_xy[0] * move_step;
		*new_y += comet->config.dir_xy[1] * move_step;
	}
	else if (key == 115)
	{
		*new_x -= comet->config.dir_xy[0] * move_step;
		*new_y -= comet->config.dir_xy[1] * move_step;
	}
}

int	ft_key_hook(int key, t_cub3d *comet)
{
	double	new_x;
	double	new_y;

	new_x = comet->config.play_xy[0];
	new_y = comet->config.play_xy[1];
	ft_printf("key == %d\n", key);
	if (key == ESC)
		ft_clean_exit(comet, 0);
	else if (key == 100 || key == 97 || key == 119 || key == 115)
		ft_handle_movement(key, comet, &new_x, &new_y);
	else if (key == 65361 || key == 113)
		rotate_player(&comet->config.dir_xy[0], &comet->config.dir_xy[1], -10);
	else if (key == 65363 || key == 101)
		rotate_player(&comet->config.dir_xy[0], &comet->config.dir_xy[1], 10);
	else
		return (1);
	if (ft_strchr("0NESW", comet->config.map[(int)new_y][(int)new_x]))
	{
		comet->config.play_xy[0] = new_x;
		comet->config.play_xy[1] = new_y;
	}
	ft_gen_frame(comet);
	return (0);
}
