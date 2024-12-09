/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <jepatern@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:24:23 by jepatern          #+#    #+#             */
/*   Updated: 2024/05/13 17:49:40 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ptr;
	char	*str;

	if ((!s2 || !s2[0]))
		return (ft_strdup(s1, 1));
	else if ((!s1 || !s2[0]))
		return (ft_strdup(s2, 1));
	str = (char *)s1;
	ptr = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!(ptr))
		return (NULL);
	while (*str != '\0')
		*ptr++ = *str++;
	str = (char *)s2;
	while (*str != '\0')
		*ptr++ = *str++;
	*ptr = '\0';
	ptr = ptr - (ft_strlen(s1) + ft_strlen(s2));
	ft_free(&s1);
	ft_free(&s2);
	return (ptr);
}
