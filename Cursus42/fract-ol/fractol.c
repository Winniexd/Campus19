/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:19:45 by winniexd          #+#    #+#             */
/*   Updated: 2023/06/15 00:11:30 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **argv)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)ft_calloc(1, sizeof(t_fractol));
	if (!fractol)
		return (-1);
	if (ac == 2 || ac == 4)
	{
		init_mlx(fractol, argv);
		init_fractol(fractol, argv);
		mlx_mouse_hook(fractol->win, mouse_hook, fractol);
		mlx_hook(fractol->win, 17, 1L << 2, &destroy_window, fractol);
		mlx_key_hook(fractol->win, key_hook, fractol);
		mlx_loop(fractol->mlx);
	}
	else if (ac == 3 && ft_strcmp(argv[1], "julia") == 0)
		ft_printf("Usage: ./fractol julia <float> <float>\n");
	else
		ft_printf("Usage: ./fractol [fractal]\n");
	free(fractol);
	return (0);
}