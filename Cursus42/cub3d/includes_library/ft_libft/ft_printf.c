/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:05:23 by jepatern          #+#    #+#             */
/*   Updated: 2021/10/11 16:05:26 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tri(char choice, va_list strin)
{
	if (choice == 'd' || choice == 'i')
		return (ft_wint(va_arg(strin, int), 0));
	else if (choice == 'u')
		return (ft_wint(va_arg(strin, int), 1));
	else if (choice == 'c')
		return (ft_wchar(va_arg(strin, int)));
	else if (choice == 's')
		return (ft_wstr(va_arg(strin, char *)));
	else if (choice == 'p')
		return (ft_wptr(va_arg(strin, void *)));
	else if (choice == 'x')
		return (ft_whex(va_arg(strin, int), "0123456789abcdef", 1));
	else if (choice == 'X')
		return (ft_whex(va_arg(strin, int), "0123456789ABCDEF", 1));
	else if (choice == '%')
		return (ft_wchar('%'));
	return (0);
}

int	ft_putstr(char *str)
{
	if (str)
		return (write(1, str, ft_strlen(str)));
	return (0);
}

int	ft_wchar(int c)
{
	return (write (1, &c, 1));
}

int	ft_printf(const char *strin, ...)
{
	va_list	ap;
	int		i;
	int		buff;

	buff = 0;
	i = 0;
	va_start (ap, strin);
	while (strin[i])
	{
		if (strin[i] == '%' && strin[i + 1] != '\0')
		{
			i++;
			buff += ft_tri(strin[i++], ap) - 2;
		}
		else if (write(1, &strin[i], 1))
			i++;
	}
	va_end(ap);
	return (i + buff);
}
