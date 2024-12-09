/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:04:47 by matias            #+#    #+#             */
/*   Updated: 2024/11/16 13:17:01 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parse_xpm(t_img *img, char *path)
{
	img->mlx = mlx_init();
	if (!img->mlx)
		return (KO);
	img->mlx_img = mlx_xpm_file_to_image(img->mlx, path, &(img->width),
			&(img->height));
	if (!img->mlx_img)
		return (KO);
	img->addr = mlx_get_data_addr(img->mlx_img, &(img->bpp), &(img->length),
			&(img->endian));
	return (OK);
}
