/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:43:52 by mdreesen          #+#    #+#             */
/*   Updated: 2023/04/07 12:43:54 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_strarrlen(char **strs, int size)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	return (len);
}

int	handle_error(int size, char **strs, char *sep)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!size || !strs[i] || !sep)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (handle_error(size, strs, sep))
		return (malloc(sizeof(char)));
	i = 0;
	k = 0;
	j = ft_strarrlen(strs, size);
	j += (size - 1) * ft_strlen(sep);
	str = (char *)malloc(j + 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			str[k++] = sep[j++];
		i++;
	}
	str[k] = '\0';
	return (str);
}
