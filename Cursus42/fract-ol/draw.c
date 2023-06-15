/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:58:13 by winniexd          #+#    #+#             */
/*   Updated: 2023/06/15 14:17:32 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    draw_fractal(t_fractol *f)
{
    if (f->fractype == 1)
        draw_mandelbrot(f);
    else if (f->fractype == 2)
        draw_burningship(f);
    else if (f->fractype == 3)
        draw_julia(f);
    else
        destroy_window(f);
}

void pxl_color(t_fractol *f, int color)
{
    unsigned int *dst = (unsigned int *)(f->addr);
    dst[f->y * f->line_length / (f->bpp / 8) + f->x] = color;
}