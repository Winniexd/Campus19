/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:04:47 by matias            #+#    #+#             */
/*   Updated: 2024/12/11 18:42:38 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parse_xpm(t_img *img, char *path)
{
	if (!path)
		return (KO);
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
