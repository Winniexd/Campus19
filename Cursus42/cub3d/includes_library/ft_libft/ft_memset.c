/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:50:40 by jepatern          #+#    #+#             */
/*   Updated: 2024/12/05 23:48:14 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	if (!b || len == 0)
		return (0);
	str = b;
	while (len)
	{
		*str = c;
		str++;
		len--;
	}
	return (b);
}
