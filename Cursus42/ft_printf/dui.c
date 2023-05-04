/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:09:11 by mdreesen          #+#    #+#             */
/*   Updated: 2023/05/02 14:09:11 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		len += 11;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		len++;
		len += ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		len++;
	}
	return (len);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putnbr_unsigned(n / 10);
		len += ft_putnbr_unsigned(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		len++;
	}
	return (len);
}

void	handle_int(t_data *data, va_list args)
{
	int	nbr;

	nbr = va_arg(args, int);
	data->len += ft_putnbr(nbr);
}

void	handle_unsigned_int(t_data *data, va_list args)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	data->len += ft_putnbr_unsigned(nbr);
}
