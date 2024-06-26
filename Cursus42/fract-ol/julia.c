/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:08:00 by winniexd          #+#    #+#             */
/*   Updated: 2024/04/02 15:43:42 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_fractol *f, char **argv)
{
	f->fractype = 3;
	f->center_x = -2.0;
	f->center_y = -2.0;
	f->zoom = 300;
	f->iter = 100;
	f->freeze = 1;
	if (argv[2] && argv[3])
	{
		f->re_c = ft_atof(argv[2]);
		f->im_c = ft_atof(argv[3]);
	}
}

static void	get_julia_pxl(t_fractol *f)
{
	double	tmp;
	int		n;
	double	zr;
	double	zi;

	zr = (f->x / f->zoom + f->center_x);
	zi = (f->y / f->zoom + f->center_y);
	n = 0;
	while (n < f->iter && (zr * zr + zi * zi) < 4)
	{
		tmp = zr * zr - zi * zi;
		zi = 2 * zr * zi + f->im_c;
		zr = tmp + f->re_c;
		n++;
	}
	if (n == f->iter)
		pxl_color(f, 0);
	else
		pxl_color(f, f->color & ~f->mask * n);
}

void	draw_julia(t_fractol *f)
{
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_length, &f->endian);
	f->x = 0;
	while (f->x < WIDTH)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			get_julia_pxl(f);
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_destroy_image(f->mlx, f->img);
}
