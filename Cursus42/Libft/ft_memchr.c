/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:40:30 by mdreesen          #+#    #+#             */
/*   Updated: 2023/04/07 11:57:09 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*str2;

	i = 0;
	str2 = (unsigned char *)str;
	while (i < n)
	{
		if (str2[i] == (unsigned char)c)
			return (str2 + i);
		i++;
	}
	return (NULL);
}
