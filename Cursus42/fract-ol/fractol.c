/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:19:45 by winniexd          #+#    #+#             */
/*   Updated: 2024/01/18 15:48:42 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc != 2 && argc != 4)
		return (ft_printf("Usage: ./fractol [fractal]\n"));
	if (argc != 4 && argv[1] && ft_strcmp(argv[1], "julia") == 0)
		return (ft_printf("Usage: ./fractol julia <float> <float>\n"));
	else if (argc != 2 && argv[1] && ft_strcmp(argv[1], "julia") == 1)
		return (ft_printf("Usage: ./fractol [fractal]\n"));
	fractol = (t_fractol *)ft_calloc(1, sizeof(t_fractol));
	if (!fractol)
		return (1);
	init_mlx(fractol, argv);
	init_fractol(fractol, argv);
	mlx_hook(fractol->win, 17, 1L << 2, &destroy_window, fractol);
	mlx_key_hook(fractol->win, key_hook, fractol);
	mlx_mouse_hook(fractol->win, mouse_hook, fractol);
	mlx_loop(fractol->mlx);
	free(fractol);
	return (0);
}
