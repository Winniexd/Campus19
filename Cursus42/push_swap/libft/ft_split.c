/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:44:55 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/20 10:47:50 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	**ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

int	check_valid(char const *s, char c)
{
	char	**str;

	if (!s || !ft_count_words(s, c))
		return (1);
	str = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!str || ft_count_words(s, c) == 0)
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (check_valid(s, c))
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			str[j] = (char *)malloc(sizeof(char) * (ft_word_len(s + i, c) + 1));
			if (!str[j])
				return (ft_free(str, j));
			ft_strlcpy(str[j], s + i, ft_word_len(s + i, c) + 1);
			j++;
			i += ft_word_len(s + i, c);
		}
		else
			i++;
	}
	str[j] = NULL;
	return (str);
}
