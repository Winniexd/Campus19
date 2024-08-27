/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:30:43 by matias            #+#    #+#             */
/*   Updated: 2024/08/27 10:41:37 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	c;

	if (argc != 2)
		return (write_err("Error\nInvalid arguments\n", 1));
	if (init_cub3d(&c, argv[1]))
		clean_exit(&c, 1);
	init_mlx(&c);
	//mlx_hook(c.win, 2, 1L<<0, key_hook, &c);
	//mlx_loop(c.mlx);
	clean_exit(&c, 0);
	return (0);
}
