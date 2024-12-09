/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:51:35 by jepatern          #+#    #+#             */
/*   Updated: 2023/04/03 11:51:36 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	putnbr(long n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		putnbr(-n, fd);
	}
	else if (n >= 10)
	{
		putnbr(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	putnbr(n, fd);
}
