/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:57:42 by mdreesen          #+#    #+#             */
/*   Updated: 2023/02/27 11:45:43 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		n;
	char	buf[7];
	int		i;
	int		j;

	n = 100;
	while (n <= 9998)
	{
		i = n / 100;
		j = n % 100;
		buf[0] = i / 10 + '0';
		buf[1] = i % 10 + '0';
		buf[2] = ' ';
		buf[3] = j / 10 + '0';
		buf[4] = j % 10 + '0';
		if (n != 9998)
		{
			buf[5] = ',';
			buf[6] = ' ';
			write(1, buf, 6);
		}
		else
			write(1, buf, 5);
		n++;
	}
}