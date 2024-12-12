/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:17:20 by matias            #+#    #+#             */
/*   Updated: 2024/12/11 18:06:14 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Checks if the path has the specified suffix
int	ft_suffix(char *path, char *suffix)
{
	int	i;
	int	j;

	i = ft_strlen(path) - 1;
	j = ft_strlen(suffix) - 1;
	while (j >= 0)
	{
		if (path[i] != suffix[j])
			return (1);
		i--;
		j--;
	}
	return (0);
}

char	*ft_get_path(char *line, int j)
{
	int		len;
	char	*path;
	int		i;

	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	len = j;
	while (line[len] && (line[len] != '\n'))
		len++;
	path = malloc((len - j + 1) * sizeof(char));
	if (!path)
		return (NULL);
	i = 0;
	while (j < len)
		path[i++] = line[j++];
	path[i] = '\0';
	return (path);
}
