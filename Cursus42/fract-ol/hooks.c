/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:49:04 by winniexd          #+#    #+#             */
/*   Updated: 2023/06/15 00:19:06 by winniexd         ###   ########.fr       */
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

/*
static void	key_hook_color(int key, t_fractol *f)
{
	if (key == KEY_ONE)
		f->color = 0x00FF0000;
	else if (key == KEY_TWO)
		f->color = 0x0000FF00;
	else if (key == KEY_TREE)
		f->color = 0x000000FF;
	else if (key == KEY_FOUR)
		f->color = 0x00FFFFFF;
	else if (key == KEY_FIVE)
		f->color = 0x00FFFF00;
	else if (key == KEY_SIX)
		f->color = 0x0000FFFF;
	else if (key == KEY_SEVEN)
		f->color = 0x00FF00FF;
	else if (key == KEY_EIGHT)
		f->color = 0x0000FFF0;
	else if (key == KEY_NINE)
		f->color = 0x00FF7F7f;
}
*/
/*
static void	key_hook_function(int key, t_fractol *f)
{
	if (key == KEY_F1)
		preset_julia(f, 0.285, 0.01);
	else if (key == KEY_F2)
		preset_julia(f, -0.4, 0.6);
	else if (key == KEY_F3)
		preset_julia(f, -0.70176, -0.3842);
	else if (key == KEY_F4)
		preset_julia(f, -0.835, -0.2321);
	else if (key == KEY_F5)
		preset_julia(f, -0.8, 0.156);
	else if (key == KEY_F6)
		preset_julia(f, -0.7269, 0.1889);
	else if (key == KEY_F7)
		preset_julia(f, 0.0, -0.8);
	else if (key == KEY_F8)
		preset_julia(f, -0.63, 0.67);
	else if (key == KEY_F9)
		preset_julia(f, 0.35, 0.05);
	else if (key == KEY_F10)
		preset_julia(f, -0.76, 0.12);
	else if (key == KEY_F11)
		preset_julia(f, -0.1222, 0.7444);
	else if (key == KEY_F12)
		preset_julia(f, -1.0, 0.0);
}
*/
/*
static void	key_hook_switch(int key, t_fractol *f)
{
	if (key == KEY_ZERO)
	{
		if (f->mask == 0x00000000)
			f->mask = 0x000F0F0F;
		else if (f->mask == 0x000F0F0F)
			f->mask = 0x00F0F0F0;
		else
			f->mask = 0x00000000;
	}
	else if (key == KEY_SPC)
	{
		if (f->fractype == 0)
			init_julia(f);
		else if (f->fractype == 1)
			init_ship(f);
		else
			init_mandel(f);
	}
}
*/

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