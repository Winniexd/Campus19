/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:04:14 by mdreesen          #+#    #+#             */
/*   Updated: 2024/10/10 15:37:33 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Two functions that are not defined in the linux minilibx
int	mlx_destroy_display(void *mlx_ptr)
{
	(void)mlx_ptr;
	return (1);
}

int	mlx_loop_end(void *mlx_ptr)
{
	(void)mlx_ptr;
	return (1);
}
