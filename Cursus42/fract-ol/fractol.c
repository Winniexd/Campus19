/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:19:45 by winniexd          #+#    #+#             */
/*   Updated: 2024/04/01 17:54:13 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_print_error(char *str, int code)
{
    ft_putendl_fd(str, 0);
    return (code);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc != 2 && argc != 4)
		return (ft_print_error("Usage: ./fractol [fractal]\n", 1));
	if (argc != 4 && argv[1] && ft_strcmp(argv[1], "julia") == 0)
		return (ft_print_error("Usage: ./fractol julia <float> <float>\n", 2));
	else if (argc != 2 && argv[1] && ft_strcmp(argv[1], "julia") == 1)
		return (ft_print_error("Usage: ./fractol [fractal]\n", 3));
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
