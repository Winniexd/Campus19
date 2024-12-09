/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:50:07 by jepatern          #+#    #+#             */
/*   Updated: 2023/04/03 11:50:08 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;

	c = c % 256;
	ptr = (char *)s;
	while (n != 0)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
		n--;
	}
	if (n == 0)
		return (NULL);
	else
		return (ptr);
}
