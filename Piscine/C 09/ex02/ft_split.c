/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:10:47 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/09 19:13:34 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_word_count(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (count);
}

static int	ft_word_len(char const *str, char c)
{
	int	len;

	len = 0;
	while (*str && *str != c)
	{
		len++;
		str++;
	}
	return (len);
}

char	**ft_split(char const *str, char charset)
{
	char	**tab;
	int		i;
	int		wc;
	int		wl;

	if (!s)
		return (NULL);
	wc = ft_word_count(str, charset);
	tab = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < wc)
	{
		while (*str && *str == charset)
			s++;
		wl = ft_word_len(str, charset);
		tab[i] = (char *)malloc(sizeof(char) * (wl + 1));
		if (!tab[i])
			return (NULL);
		tab[i][wl] = '\0';
		while (wl--)
			tab[i][wl] = *(str + wl);
		s += ft_word_len(str, charset);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
