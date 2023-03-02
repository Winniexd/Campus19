/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:14:42 by mdreesen          #+#    #+#             */
/*   Updated: 2023/02/27 11:15:10 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb_helper(int i, int j, int k, char *str)
{
	while (i < 10)
	{
		while (j < 10)
		{
			while (k < 10)
			{
				str[0] = i + '0';
				str[1] = j + '0';
				str[2] = k + '0';
				str[3] = '\0';
				write(1, str, 3);
				if (i != 7)
				{
					write(1, ", ", 2);
				}
				k++;
			}
			j++;
			k = j + 1;
		}
		i++;
		j = i + 1;
		k = j + 1;
	}
}

void	ft_print_comb(void)
{
	char	str[4];
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 1;
	k = 2;
	ft_print_comb_helper(i, j, k, str);
}
