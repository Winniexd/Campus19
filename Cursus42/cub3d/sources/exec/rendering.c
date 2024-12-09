/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:43:32 by winniexd          #+#    #+#             */
/*   Updated: 2024/12/07 14:01:35 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_gen_frame(t_cub3d *comet)
{
	t_r		ray_data;
	t_frame	frame;
	t_rc	rc;

	rc.offset = 60.0 / 2;
	rc.d_angle = 60.0 / WIDTH;
	ft_create_base_image(comet, &frame);
	ft_draw_frame(comet, &frame, &ray_data, &rc);
	mlx_put_image_to_window(comet->mlx, comet->win, frame.addr, 0, 0);
	mlx_destroy_image(comet->mlx, frame.addr);
}

void	ft_create_base_image(t_cub3d *c, t_frame *img)
{
	int	y;
	int	half_height;
	int	color;
	int	x;

	img->addr = mlx_new_image(c->mlx, WIDTH, HEIGHT);
	img->raw = mlx_get_data_addr(img->addr, &img->bpp, &img->length,
			&img->endian);
	half_height = HEIGHT / 2;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		if (y < half_height)
			color = c->config.ceiling_trgb;
		else
			color = c->config.floor_trgb;
		while (x < WIDTH)
		{
			ft_px_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_draw_frame(t_cub3d *c, t_frame *frame, t_r *ray_data, t_rc *rc)
{
	int			i;
	t_img		*selected_texture;
	double		offset;
	t_config	*config;

	config = &c->config;
	i = -1;
	while (++i < WIDTH)
	{
		offset = ft_degrees_to_radians((i - WIDTH / 2) * rc->d_angle);
		rc->dir_x = config->dir_xy[0] * cos(offset) - config->dir_xy[1]
			* sin(offset);
		rc->dir_y = config->dir_xy[0] * sin(offset) + config->dir_xy[1]
			* cos(offset);
		ft_cast_ray(config->play_xy, rc, c->config.map, ray_data);
		ray_data->distance = ray_data->d * cos(ft_degrees_to_radians((i - WIDTH
						/ 2) * rc->d_angle));
		selected_texture = &c->img[ft_choose("NSWE", ray_data->wall_dir)];
		ft_vertical_slice(frame, selected_texture, i, ray_data);
	}
}

void	ft_draw_line(t_frame *img, t_img *texture, int x, t_d *draw_data)
{
	double	step;
	double	tex_pos;
	int		y;
	int		tex_y;
	char	*pixel;

	step = (double)texture->height / draw_data->h;
	tex_pos = (draw_data->start - HEIGHT / 2 + draw_data->h / 2) * step;
	y = draw_data->start - 1;
	while (++y < draw_data->end)
	{
		tex_y = (int)tex_pos % texture->height;
		tex_pos += step;
		if (tex_y >= 0 && tex_y < texture->height)
		{
			pixel = texture->addr + (tex_y * texture->length + draw_data->t_x
					* (texture->bpp / 8));
			ft_px_put(img, x, y, *(unsigned int *)pixel);
		}
	}
}

void	ft_vertical_slice(t_frame *img, t_img *texture, int col, t_r *ray_data)
{
	t_d	draw_data;

	draw_data.h = (int)(HEIGHT / ray_data->distance);
	if (-draw_data.h / 2 + HEIGHT / 2 < 0)
		draw_data.start = 0;
	else
		draw_data.start = -draw_data.h / 2 + HEIGHT / 2;
	if (draw_data.h / 2 + HEIGHT / 2 >= HEIGHT)
		draw_data.end = HEIGHT - 1;
	else
		draw_data.end = draw_data.h / 2 + HEIGHT / 2;
	draw_data.t_x = (int)(ray_data->w_x * texture->width) % texture->width;
	ft_draw_line(img, texture, col, &draw_data);
}
