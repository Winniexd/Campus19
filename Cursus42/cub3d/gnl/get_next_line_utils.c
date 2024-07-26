/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:33:39 by mdreesen          #+#    #+#             */
/*   Updated: 2024/07/26 14:33:38 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	if (c == 0)
	{
		i = ft_strlen((char *)s);
		return (&s[i]);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *start, char *buff)
{
	size_t	start_len;
	size_t	buff_len;
	char	*result;

	start_len = 0;
	buff_len = 0;
	if (start)
		start_len = ft_strlen(start);
	if (buff)
		buff_len = ft_strlen(buff);
	result = (char *)malloc(start_len + buff_len + 1);
	if (!result)
		return (NULL);
	if (start)
		ft_memcpy(result, start, start_len);
	if (buff)
		ft_memcpy(result + start_len, buff, buff_len);
	result[start_len + buff_len] = '\0';
	free(start);
	return (result);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(ft_strlen(src) + 1);
	if (!str)
		return (NULL);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
