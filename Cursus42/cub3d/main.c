/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:43:49 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/28 13:38:12 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	*c;

	if (argc != 2)
		return (write_err("Incorrect argument count", 1));
	c = malloc(sizeof(t_cub3d));
	if (!c)
		return (write_err("Malloc error", 2));
	init_mlx(c);
	init_map(c, argv[1]);
	mlx_hook(c->win, 17, 1L << 2, &free_mlx, c);
	mlx_key_hook(c->win, key_hook, c);
	mlx_loop(c->mlx);
	free(c);
	return (0);
}
