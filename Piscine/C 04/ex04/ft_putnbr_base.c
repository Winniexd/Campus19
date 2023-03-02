/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:43:47 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/02 13:24:07 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char *str)
{
        int     i;

        i = 0;
        while (str[i] != '\0')
        {
                write(1, &str[i], 1);
                i++;
        }
}

void	ft_turnbin(int n)
{
	char	binary[32];
	int		i;

	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (n > 0)
	{
		binary[i] = '0' + n % 2;
		n /= 2;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(1, &binary[i - 1], 1);
	}
}

void	ft_turn_octal(int n)
{
	char	octal[32];
	int		i;

	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (n > 0)
	{
		octal[i] = '0' + n % 8;
		n /= 8;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(1, &octal[i], 1);
	}
}

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	c = '0' + n % 10;
	write(1, &c, 1);
}

void	turn_to_hex(int nbr, char *hex_buffer)
{
	int	upper_nibble;
	int	lower_nibble;

	upper_nibble = (nbr >> 4) & 0xF;
	lower_nibble = nbr & 0xF;
	hex_buffer[0] = (upper_nibble <= 9) ? (upper_nibble + '0') : (upper_nibble
			- 10 + 'A');
	hex_buffer[1] = (lower_nibble <= 9) ? (lower_nibble + '0') : (lower_nibble
			- 10 + 'A');
	hex_buffer[2] = '\0';
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	hex_buffer[3];

	if (base == "0123456789")
	{
		ft_putnbr(nbr);
	}
	else if (base == "01")
	{
		ft_turnbin(nbr);
	}
	else if (base == "0123456789ABCDEF")
	{
		turn_to_hex(nbr, hex_buffer);
		ft_putchar(hex_buffer);
	}
	else if (base == "poneyvif")
	{
		ft_turn_octal(nbr);
	}
	else
	{
		return ;
	}
}
