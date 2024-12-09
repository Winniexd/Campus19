/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:29 by jepatern          #+#    #+#             */
/*   Updated: 2023/04/03 12:23:30 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	c = c % 256;
	ptr = NULL;
	while (*s)
	{
		if (*s == c)
			ptr = ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (ptr);
}
