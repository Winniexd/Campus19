/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepatern <jepatern@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:01:26 by jepatern          #+#    #+#             */
/*   Updated: 2024/05/02 15:42:52 by jepatern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dclen(unsigned long nb)
{
	int	i;

	i = 0;
	while (nb != 0 && ++i)
		nb /= 16;
	return (i);
}

int	ft_whex(unsigned long nb, char *base, int code)
{
	int		len;
	char	*str;

	if (code == 1)
		nb = (unsigned int)nb;
	len = ft_dclen(nb);
	if (!len)
		return (write(1, "0", 1));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (nb && len)
	{
		str[--len] = base[nb % 16];
		nb /= 16;
	}
	len = ft_putstr(str);
	ft_free(&str);
	return (len);
}

int	ft_wstr(char *str)
{
	if (!str)
		return (write (1, "(null)", 6));
	return (ft_putstr(str));
}

int	ft_wptr(void *ptr)
{
	unsigned long	addr;

	if (!ptr)
		return (write(1, "0x0", 3));
	addr = (long long)ptr;
	if (write(1, "0x", 2))
		return (ft_whex(addr, "0123456789abcdef", 0) + 2);
	return (0);
}

int	ft_wint(long long nb, int code)
{
	char			*str;
	int				i;

	if (code == 1)
		nb = (unsigned int)nb;
	str = ft_itoa(nb);
	i = ft_putstr(str);
	free (str);
	return (i);
}
