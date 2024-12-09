/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:24:12 by jepatern          #+#    #+#             */
/*   Updated: 2023/04/03 12:24:13 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		ix;

	i = -1;
	if (!haystack || !needle || !needle[0])
		return ((char *)haystack);
	while (haystack[++i] != '\0' && i < len)
	{
		ix = 0;
		while (needle[ix] == haystack[i + ix] && i + ix < len)
			if (needle[ix++ + 1] == '\0')
				return ((char *)haystack + i);
	}
	return (NULL);
}
