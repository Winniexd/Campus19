/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:54:32 by matias            #+#    #+#             */
/*   Updated: 2024/12/04 11:48:55 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_cast_ray(double *pxy, t_rc *rc, char **map, t_r *rdata)
{
	t_rdata	ray_info;

	ray_info.hit_side = 0;
	ft_init_rdata(pxy, rc->dir_x, rc->dir_y, &ray_info);
	ft_find_wall(&ray_info, map);
	ft_calculate_ray(pxy, rc, &ray_info, rdata);
}

void	ft_init_rdata(double *pxy, double dir_x, double dir_y, t_rdata *rdata)
{
	rdata->map_x = (int)pxy[0];
	rdata->map_y = (int)pxy[1];
	rdata->ddx = fabs(1 / dir_x);
	rdata->ddy = fabs(1 / dir_y);
	rdata->step_y = 1;
	rdata->step_x = 1;
	if (dir_x < 0)
	{
		rdata->step_x *= -1;
		rdata->side_dist_x = (pxy[0] - rdata->map_x) * rdata->ddx;
	}
	else
		rdata->side_dist_x = (rdata->map_x + 1.0 - pxy[0]) * rdata->ddx;
	if (dir_y < 0)
	{
		rdata->step_y *= -1;
		rdata->side_dist_y = (pxy[1] - rdata->map_y) * rdata->ddy;
	}
	else
		rdata->side_dist_y = (rdata->map_y + 1.0 - pxy[1]) * rdata->ddy;
}

void	ft_find_wall(t_rdata *ray_info, char **map)
{
	while (ft_there_is_c("0SNWE \n", map[ray_info->map_y][ray_info->map_x]))
	{
		if (ray_info->side_dist_x < ray_info->side_dist_y)
		{
			ray_info->side_dist_x += ray_info->ddx;
			ray_info->map_x += ray_info->step_x;
			ray_info->hit_side = 0;
		}
		else
		{
			ray_info->side_dist_y += ray_info->ddy;
			ray_info->map_y += ray_info->step_y;
			ray_info->hit_side = 1;
		}
	}
}

void	ft_calculate_ray(double *pxy, t_rc *rc, t_rdata *ray_info, t_r *rdata)
{
	if (ray_info->hit_side == 0)
	{
		rdata->wall_dir = 'W';
		rdata->d = (ray_info->map_x - pxy[0] + (1 - ray_info->step_x) / 2)
			/ rc->dir_x;
		rdata->w_x = pxy[1] + rdata->d * rc->dir_y;
		if (ray_info->step_x > 0)
			rdata->wall_dir = 'E';
	}
	else
	{
		rdata->wall_dir = 'N';
		rdata->d = (ray_info->map_y - pxy[1] + (1 - ray_info->step_y) / 2)
			/ rc->dir_y;
		rdata->w_x = pxy[0] + rdata->d * rc->dir_x;
		if (ray_info->step_y > 0)
			rdata->wall_dir = 'S';
	}
}
