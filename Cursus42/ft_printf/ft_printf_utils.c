/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:22:53 by mdreesen          #+#    #+#             */
/*   Updated: 2023/04/23 15:41:22 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void ft_putchar(const char c)
{
	write(1, &c, 1);
}

size_t ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int ft_numlen(int num)
{
	int len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

int ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int len;
	unsigned int base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
	{
		len += ft_putnbr_base(nbr / base_len, base);
		len += ft_putnbr_base(nbr % base_len, base);
	}
	else
	{
		ft_putchar(base[nbr]);
		len++;
	}
	return (len);
}
