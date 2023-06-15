/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:49:04 by winniexd          #+#    #+#             */
/*   Updated: 2023/06/15 14:07:46 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(int x, int y, t_fractol *f)
{
	f->center_x = (x / f->zoom + f->center_x) - (x / (f->zoom * 1.5));
	f->center_y = (y / f->zoom + f->center_y) - (y / (f->zoom * 1.5));
	f->zoom *= 1.5;
}

void	zoom_out(int x, int y, t_fractol *f)
{
	f->center_x = (x / f->zoom + f->center_x) - (x / (f->zoom / 1.5));
	f->center_y = (y / f->zoom + f->center_y) - (y / (f->zoom / 1.5));
	f->zoom /= 1.5;
}

void print_values(t_fractol *f)
{
	printf("f->center_x = %f\n", f->center_x);
	printf("f->center_y = %f\n", f->center_y);
	printf("f->zoom = %f\n", f->zoom);
	printf("f->iter = %d\n", f->iter);
	printf("f->color = %d\n", f->color);
	printf("f->fractype = %d\n", f->fractype);
	printf("f->mask = %d\n", f->mask);
}

int	key_hook(int key, t_fractol *f)
{
	if (key == ESC)
		destroy_window(f);
	else if (key == LEFT || key == A)
		f->center_x -= 10.0 / f->zoom;
	else if (key == RIGHT || key == D)
		f->center_x += 10.0 / f->zoom;
	else if (key == UP || key == W)
		f->center_y -= 10.0 / f->zoom;
	else if (key == DOWN || key == S)
		f->center_y += 10.0 / f->zoom;
	else if (key == Z)
		zoom_in((WIDTH / 2), (HEIGHT / 2), f);
	else if (key == X)
		zoom_out((WIDTH / 2), (HEIGHT / 2), f);
	else if (key == PLUS)
		f->iter += 10;
	else if (key == MINUS)
		f->iter -= 10;
	//key_hook_switch(key, f);
	//key_hook_function(key, f);
	//key_hook_color(key, f);
	print_values(f);
	draw_fractal(f);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	if (button == 4)
		zoom_in(x, y, f);
	else if (button == 5)
		zoom_out(x, y, f);
	else if (button == 1)
	{
		f->re_c = (x - (double)WIDTH / 2) / (f->zoom);
		f->im_c = (y - (double)HEIGHT / 2) / (f->zoom);
	}
	draw_fractal(f);
	return (0);
}