/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:25:38 by jepatern          #+#    #+#             */
/*   Updated: 2023/04/03 12:25:39 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sptr;
	int		i;

	if (!s || !f)
		return (NULL);
	sptr = (char *)malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (!sptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		sptr[i] = f(i, s[i]);
		++i;
	}
	sptr[i] = '\0';
	return (sptr);
}
