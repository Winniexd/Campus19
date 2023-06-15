/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:08:00 by winniexd          #+#    #+#             */
/*   Updated: 2023/06/15 14:26:33 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init_julia(t_fractol *f, char **argv)
{
    f->fractype = 3;
    f->center_x = -2.0;
    f->center_y = -2.0;
    f->zoom = 300;
    f->iter = 100;
    f->color = 0x00FF00;
    f->mask = 0x00FFFF;
    if (argv[2] && argv[3])
    {
        f->re_c = ft_atof(argv[2]);
        f->im_c = ft_atof(argv[3]);
    }
}

void find_julia_pixel(t_fractol *f)
{
    int     n;
    double  zr;
    double  zi;
    double  tmp;

    zr = f->x / f->zoom + f->center_x;
    zi = f->y / f->zoom + f->center_y;
    n = 0;
    while (n < f->iter && (zr * zr + zi * zi) < 4.0)
    {
        tmp = zr * zr - zi * zi;
        zr = tmp + f->re_c;
        zi = 2.0 * zr * zi + f->im_c;
        n++;
    }
    if (n == f->iter)
        pxl_color(f, 0);
    else
        pxl_color(f, f->color & ~f->mask * n);
}

void    draw_julia(t_fractol *f)
{
    f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_length, &f->endian);
    f->x = 0;
    while (f->x < WIDTH)
    {
        f->y = 0;
        while (f->y < HEIGHT)
        {
            find_julia_pixel(f);
            f->y++;
        }
        f->x++;
    }
    mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
    mlx_destroy_image(f->mlx, f->img);
}