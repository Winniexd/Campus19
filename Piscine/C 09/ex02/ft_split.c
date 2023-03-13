/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 09:10:18 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/11 09:10:20 by mdreesen         ###   ########.fr       */
=======
/*   By: mdreesen <mdreesen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:10:47 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/09 19:13:34 by mdreesen         ###   ########.fr       */
>>>>>>> a86b22c6d44f1f310bfd753c54d8541c5032d12b
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

<<<<<<< HEAD
int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
=======
static int	ft_word_count(char const *str, char c)
>>>>>>> a86b22c6d44f1f310bfd753c54d8541c5032d12b
{
	int	count;

	count = 0;
	while (*str)
	{
<<<<<<< HEAD
		while (*str && is_separator(*str, charset))
			str++;
		if (*str && !is_separator(*str, charset))
		{
			count++;
			while (*str && !is_separator(*str, charset))
				str++;
		}
=======
		if (*str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
>>>>>>> a86b22c6d44f1f310bfd753c54d8541c5032d12b
	}
	return (count);
}

<<<<<<< HEAD
char	*get_word(char *str, char *charset)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && !is_separator(str[i], charset))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (*str && !is_separator(*str, charset))
	{
		word[i] = *str;
		i++;
		str++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**words;
	int		count;
	int		i;

	count = count_words(str, charset);
	words = (char **)malloc(sizeof(char *) * (count + 1));
	i = 0;
	while (*str)
	{
		while (*str && is_separator(*str, charset))
			str++;
		if (*str && !is_separator(*str, charset))
		{
			words[i] = get_word(str, charset);
			i++;
			while (*str && !is_separator(*str, charset))
				str++;
		}
	}
	words[i] = NULL;
	return (words);
=======
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
>>>>>>> a86b22c6d44f1f310bfd753c54d8541c5032d12b
}
