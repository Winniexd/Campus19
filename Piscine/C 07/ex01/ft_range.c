/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:02:26 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/11 11:33:13 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

int	*ft_range(int min, int max)
{
	int	range;
	int	i;
	int	*array;

	if (min >= max)
		return ((void *)0);
	range = ft_abs(max - min);
	array = malloc(range * sizeof(int));
	if (!array)
		return ((void *)0);
	i = 0;
	while (i < range)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}
