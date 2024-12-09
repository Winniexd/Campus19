/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <jepatern@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:48:43 by jepatern          #+#    #+#             */
/*   Updated: 2024/05/01 12:51:16 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip(const char *str, int *values)
{
	int	i;
	int	sign;

	i = values[0];
	sign = values[1];
	while ((str[i] == ' ') || (('\t' <= str[i]) && (str[i] <= '\r')))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	values[0] = i;
	values[1] = sign;
}

static int	border_checker(long res, long lim, int c)
{
	int	bordering;
	int	potential;
	int	value;
	int	crossover;
	int	check;

	potential = ((lim / 10) < res);
	bordering = (res == (lim / 10));
	value = c - '0';
	crossover = ((lim % 10) < value);
	check = (potential || (bordering && crossover));
	return (check);
}

int	ft_atoi(const char *str)
{
	long	res;
	int		values[2];
	long	lim;

	values[0] = 0;
	values[1] = 1;
	lim = 9223372036854775807L;
	res = 0;
	skip(str, values);
	while (ft_isdigit(str[values[0]]))
	{
		if (border_checker(res, lim, str[values[0]]))
		{
			if (values[1] == 1)
				return (-1);
			else
				return (0);
		}
		res = ((res * 10) + (str[values[0]] - '0'));
		values[0]++;
	}
	res = res * values[1];
	return (res);
}
