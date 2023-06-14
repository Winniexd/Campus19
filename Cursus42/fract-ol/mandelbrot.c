/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:30:52 by winniexd          #+#    #+#             */
/*   Updated: 2023/06/15 00:22:49 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pxl_input(t_fractol *f, int color)
{
	char	*dst;

	dst = f->addr + (f->y * f->line_length + f->x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

void	init_mandelbrot(t_fractol *f)
{
	f->fractype = 1;
	f->iter = 100;
	f->zoom = 300;
	f->center_x = -2.0;
	f->center_y = -1.5;
}

static void	find_mandelbrot_pixel(t_fractol *f)
{
	double	z_next;
	double	z_tmp;
	int		i;

	f->re_c = f->x / f->zoom + f->center_x;
	f->im_c = -(f->y / f->zoom + f->center_y);
	f->re_z = 0.0;
	f->im_z = 0.0;
	i = 0;
	z_next = 0.0;
	while (z_next < 4 && i < f->iter)
	{
		z_tmp = f->re_z;
		f->re_z = f->re_z * f->re_z - f->im_z * f->im_z + f->re_c;
		f->im_z = 2 * f->im_z * z_tmp - f->im_c;
		z_next = f->re_z * f->re_z + f->im_z * f->im_z;
		i++;
	}
	if (i == f->iter)
		pxl_input(f, 0);
	else
		pxl_input(f, f->color & ~f->mask * i);
}

void	draw_mandelbrot(t_fractol *f)
{
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_length, &f->endian);
	f->x = 0;
	while (f->x < WIDTH)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			find_mandelbrot_pixel(f);
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_destroy_image(f->mlx, f->img);
}