/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:14:42 by mdreesen          #+#    #+#             */
/*   Updated: 2023/04/07 13:19:20 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_isinset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	str = malloc(ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	while (ft_isinset(s1[i], set) == 1)
		i++;
	while (s1[i] != '\0')
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	while (ft_isinset(str[j - 1], set) == 1)
		j--;
	str[j] = '\0';
	return (str);
}
