/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:30:43 by matias            #+#    #+#             */
/*   Updated: 2024/12/11 14:28:57 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	comet;

	if (argc != 2)
		return (1);
	if (ft_init_cub3d(&comet, argv[1]))
		ft_clean_exit(&comet, 1);
	ft_display_config(&comet.config);
	ft_init_mlx(&comet);
	ft_gen_frame(&comet);
	mlx_key_hook(comet.win, ft_key_hook, &comet);
	mlx_hook(comet.win, 17, 1L << 0, ft_clean_exit, &comet);
	mlx_loop(comet.mlx);
	ft_display_config(&comet.config);
	ft_clean_exit(&comet, 0);
	return (0);
}
