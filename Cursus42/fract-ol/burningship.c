/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:13:11 by winniexd          #+#    #+#             */
/*   Updated: 2023/06/15 14:27:11 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init_burningship(t_fractol *f)
{
    f->fractype = 2;
    f->center_x = -2.0;
    f->center_y = -2.0;
    f->zoom = 225;
    f->iter = 100;
}

void    get_burningship_pixel(t_fractol *f)
{
	int		i;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	i = 0;
	while (i < f->iter && (zr * zr + zi * zi) < 4.0)
	{
		zr = fabs(zr);
		zi = fabs(zi);
		tmp = 2 * zr * zi + -(f->y / f->zoom + f->center_y);
		zr = zr * zr - zi * zi + f->x / f->zoom + f->center_x;
		zi = tmp;
		i++;
	}
	if (i == f->iter)
		pxl_color(f, 0);
	else
		pxl_color(f, f->color & ~f->mask * i);
}

void    draw_burningship(t_fractol *f)
{
    f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_length, &f->endian);
    f->y = 0;
    while (f->y < HEIGHT)
    {
        f->x = 0;
        while (f->x < WIDTH)
        {
            get_burningship_pixel(f);
            f->x++;
        }
        f->y++;
    }
    mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
    mlx_destroy_image(f->mlx, f->img);   
}