/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:17:45 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/28 11:50:37 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	write_err(char *err, int retval)
{
	printf("%s\n", err);
	return (retval);
}

int	key_hook(int key, t_cub3d *c)
{
	if (key == ESC)
		free_mlx(c);
	return (0);
}

int	ft_suffix(char *path, char *suffix)
{
	size_t	pathlen;
	size_t	sufflen;

	pathlen = ft_strlen(path);
	sufflen = ft_strlen(suffix);
	if (sufflen > pathlen)
		return (0);
	return (ft_strcmp(path + pathlen - sufflen, suffix));
}
