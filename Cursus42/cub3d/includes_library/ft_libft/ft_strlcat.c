/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:23:01 by jepatern          #+#    #+#             */
/*   Updated: 2023/04/03 12:23:02 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	len;
	unsigned int	len2;
	unsigned int	i;

	i = 0;
	len = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (dstsize < 1)
		return (len2 - dstsize);
	while (dst[i] && i != dstsize - 1)
		i++;
	while (*src && i != dstsize - 1)
		dst[i++] = *src++;
	if (dstsize > len)
		dst[i] = '\0';
	if (dstsize < len)
		return (len2 + dstsize);
	else
		return (len + len2);
}
