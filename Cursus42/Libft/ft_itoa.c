/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:45:25 by mdreesen          #+#    #+#             */
/*   Updated: 2023/04/07 12:46:24 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		neg;

	i = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!(str))
		return (NULL);
	str[i] = '\0';
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = n * -1;
	}
	while (i > 0)
	{
		str[i - 1] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
