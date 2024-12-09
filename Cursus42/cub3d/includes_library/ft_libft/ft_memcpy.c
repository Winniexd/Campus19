/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:50:25 by jepatern          #+#    #+#             */
/*   Updated: 2023/04/03 11:50:26 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char	*d;
	char	*s;
	void	*target;

	if (!src || !dst)
		return (NULL);
	d = dst;
	s = src;
	target = dst;
	while (n && *s)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (target);
}
