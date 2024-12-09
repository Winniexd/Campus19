/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:22:29 by matias            #+#    #+#             */
/*   Updated: 2024/12/07 14:04:39 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_display_config(t_config *config)
{
	int	i;

	printf("Ceiling: %d,%d,%d\n", config->ceiling[0], config->ceiling[1],
		config->ceiling[2]);
	printf("Floor: %d,%d,%d\n", config->floor[0], config->floor[1],
		config->floor[2]);
	printf("North xpm: %s\n", config->north);
	printf("East xpm: %s\n", config->east);
	printf("South xpm: %s\n", config->south);
	printf("West xpm: %s\n\n", config->west);
	printf("Player X: %f\n\n", config->play_xy[0]);
	printf("Player Y: %f\n\n", config->play_xy[1]);
	printf("Player Dir X: %f\n\n", config->dir_xy[0]);
	printf("HEI %d WID %d \n", config->height, config->width);
	i = -1;
	printf("Floor RGB: [%d,%d,%d]\n", config->floor[0],
		config->floor[1], config->floor[2]);
	printf("Floor trgb: [%d]\n", config->floor_trgb);
	printf("Ceiling RGB: [%d,%d,%d]\n", config->ceiling[0],
		config->ceiling[1], config->ceiling[2]);
	printf("Ceiling trgb: [%d]\n", config->ceiling_trgb);
	while (config->map[++i])
		ft_printf("config->map[%d] == %s\n", i, config->map[i]);
}
