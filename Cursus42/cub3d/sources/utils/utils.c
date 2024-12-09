/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:36:42 by matias            #+#    #+#             */
/*   Updated: 2024/12/04 18:59:51 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_line_count(char *path)
{
	int		fd;
	int		linecount;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	linecount = 0;
	while (line)
	{
		linecount++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (linecount);
}

void	ft_px_put(t_frame *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = img->raw + (y * img->length + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	ft_choose(char *str, char x)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == x)
			return (i);
	return (-1);
}

double	ft_degrees_to_radians(double degrees)
{
	return (degrees * 0.017453293);
}

int	ft_is_white_char(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}
