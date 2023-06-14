/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:10:43 by mdreesen          #+#    #+#             */
/*   Updated: 2023/06/13 15:27:13 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*my_strchr(const char *s)
{
	while (*s)
	{
		if (*s == '%')
			return ((char *)s);
		s++;
	}
	if (!s)
		return ((char *)s);
	return (NULL);
}
