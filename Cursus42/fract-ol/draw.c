/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:58:13 by winniexd          #+#    #+#             */
/*   Updated: 2023/06/14 14:54:04 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    draw_fractal(t_fractol *f)
{
    if (f->fractype == 1)
        draw_mandelbrot(f);
    /*
    else if (f->fractype == 1)
        draw_julia(f);
    else if (f->fractype == 2)
        draw_burningship(f);
    */
    else
        destroy_window(f);
}