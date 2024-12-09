/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <jepatern@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:31:45 by jepatern          #+#    #+#             */
/*   Updated: 2024/05/17 17:00:57 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_sdup2(const char *src, int n)
{
	int		i;
	char	*s;

	i = 0;
	while (src && src[i])
		i++;
	s = malloc(n + 1);
	if (!s)
		return (NULL);
	i = -1;
	while (src[++i] && i < n)
		s[i] = src[i];
	s[i] = '\0';
	return (s);
}

static int	ft_slen2(const char *s, char sep)
{
	int	i;

	i = 0;
	if (!s[0])
		return (0);
	while (s[i] && s[i] != sep)
		i++;
	return (i);
}

static int	ft_count_words(const char *s, char sep)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != sep)
		{
			count++;
			while (s[i] && s[i] != sep)
				i++;
			i--;
		}
		i++;
	}
	return (count);
}

char	**ft_norm(char *s, int flag, char **strs)
{
	if (flag)
		free(s);
	return (strs);
}

char	**ft_split(char *s, char c, int flag)
{
	char	**strs;
	int		size;
	int		idx[2];

	idx[1] = flag * 0;
	if (!s)
		return (0);
	size = ft_count_words(&s[0], c);
	if (size == 0)
		size++;
	strs = ft_calloc(sizeof(char *), (size + 1));
	if (!strs || size < 0)
		return (NULL);
	idx[0] = 0;
	while (idx[0] != size)
	{
		while (s[idx[1]] && s[idx[1]] == c)
			idx[1]++;
		strs[idx[0]] = ft_sdup2(&s[idx[1]], ft_slen2(&s[idx[1]], c));
		idx[0]++;
		while (s[idx[1]] && s[idx[1]] != c)
			idx[1]++;
	}
	return (ft_norm(s, flag, strs));
}
