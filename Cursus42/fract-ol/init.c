/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:25:15 by winniexd          #+#    #+#             */
/*   Updated: 2024/04/01 17:58:16 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy_window(t_fractol *f)
{
	mlx_clear_window(f->mlx, f->win);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	mlx_loop_end(f->mlx);
	free(f->mlx);
	free(f);
	exit(1);
}

void	init_mlx(t_fractol *f, char **argv)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, argv[1]);
	f->mask = 0x00F0F0F0;
	f->color = 0x000000FF;
}

void	init_fractol(t_fractol *f, char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0 && !av[2])
		init_mandelbrot(f);
	else if (ft_strcmp(av[1], "burningship") == 0 && !av[2])
		init_burningship(f);
	else if (ft_strcmp(av[1], "julia") == 0 && (av[2] && av[3]))
		init_julia(f, av);
	else
		destroy_window(f);
	draw_fractal(f);
}
