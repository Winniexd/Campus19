/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdiff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <jepatern@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:54:53 by jepatern          #+#    #+#             */
/*   Updated: 2024/05/22 12:55:13 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strdiff(char *s1, char *s2)
{
	int	difference;

	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	difference = (*s1 - *s2);
	return (difference);
}
