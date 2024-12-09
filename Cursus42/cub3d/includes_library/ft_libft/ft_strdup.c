/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <jepatern@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:24:31 by jepatern          #+#    #+#             */
/*   Updated: 2024/05/13 17:53:48 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1, int code)
{
	int		i;
	char	*str;

	i = 0;
	if (!s1 || !s1[i])
		return (NULL);
	while (s1 && s1[i])
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	if (code == 1)
		ft_free(&s1);
	return (str);
}
