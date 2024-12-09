/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:49:57 by jepatern          #+#    #+#             */
/*   Updated: 2023/04/03 12:14:48 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_lenght(long long n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(long long n)
{
	int		len;
	char	*str;

	if (n == 0)
		return (ft_strdup("0", 0));
	len = ft_lenght(n);
	str = malloc((len + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		str[len] = 48 + (n % 10);
		n = n / 10;
		len--;
	}
	return (str);
}
