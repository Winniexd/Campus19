/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:21:19 by winniexd          #+#    #+#             */
/*   Updated: 2023/06/15 13:48:29 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 900
# define HEIGHT 900

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PLUS 24
# define MINUS 27
# define W 13
# define A 0
# define S 1
# define D 2
# define Z 6
# define X 7

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		fractype;
	int		iter;
	int		color;
	int		mask;
	int		x;
	int		y;
	int		freeze;
	double	zoom;
	double	center_x;
	double	center_y;
	double	im_z;
	double	re_z;
	double	im_c;
	double	re_c;
}			t_fractol;

int			destroy_window(t_fractol *f);
int			key_hook(int key, t_fractol *f);
int			mouse_hook(int button, int x, int y, t_fractol *f);
int			motion_hook(int x, int y, t_fractol *f);

void		init_fractol(t_fractol *f, char **av);
void		init_mlx(t_fractol *f, char **argv);

void		init_mandelbrot(t_fractol *f);
void		draw_mandelbrot(t_fractol *f);

void		init_julia(t_fractol *f, char **argv);
void		find_julia_pixel(t_fractol *f);
void		draw_julia(t_fractol *f);

void		init_burningship(t_fractol *f);
void		find_burningship_pixel(t_fractol *f);
void		draw_burningship(t_fractol *f);

void		draw_fractal(t_fractol *f);
void		pxl_color(t_fractol *f, int color);

#endif