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
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < f->iter)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->y / f->zoom + f->center_y;
		zr = zr * zr - zi * zi + f->x / f->zoom + f->center_x;
		zi = tmp;
		n++;
	}
	if (n == f->iter)
		pxl_input(f, 0);
	else
		pxl_input(f, f->color & ~f->mask * n);
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