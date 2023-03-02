/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:22:17 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/02 13:07:59 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	turn_to_hex(char c, char *hex)
{
	int	upper_nibble;
	int	lower_nibble;

	upper_nibble = (c >> 4) & 0xF;
	lower_nibble = c & 0xF;
	if (upper_nibble <= 9)
	{
		hex[0] = upper_nibble + '0';
	}
	else
	{
		hex[0] = upper_nibble - 10 + 'a';
	}
	if (lower_nibble <= 9)
	{
		hex[1] = lower_nibble + '0';
	}
	else
	{
		hex[1] = lower_nibble - 10 + 'a';
	}
	hex[2] = '\0';
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	hex[3];
	int		j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
		{
			turn_to_hex(str[i], hex);
			j = i;
			while (str[j] != '\0')
				j++;
			while (j > i + 1)
			{
				str[j + 1] = str[j - 1];
				j--;
			}
			str[i] = '\\';
			str[i + 1] = hex[0];
			str[i + 2] = hex[1];
			i += 2;
		}
		i++;
	}
	ft_putchar(str);
}
