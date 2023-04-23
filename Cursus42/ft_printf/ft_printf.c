/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:37:21 by mdreesen          #+#    #+#             */
/*   Updated: 2023/04/18 11:37:22 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_parse_helper2(const char *format, t_data *data, va_list args)
{
	int		num;
	char	c;

	if (*format == 'x')
	{
		num = va_arg(args, int);
		ft_putnbr_base(num, "0123456789abcdef");
		data->len += ft_numlen(num);
	}
	else if (*format == 'c')
	{
		c = va_arg(args, int);
		ft_putchar(c);
		data->len++;
	}
	else
		return (NULL);
	format++;
	return (format);
}

const char	*ft_parse_helper(const char *format, t_data *data, va_list args)
{
	int		num;

	if (*format == 'X')
	{
		num = va_arg(args, int);
		ft_putnbr_base(num, "0123456789ABCDEF");
		data->len += ft_numlen(num);
	}
	else if (*format == 'p')
	{
		num = va_arg(args, int);
		ft_putstr("0x");
		ft_putnbr_base(num, "0123456789abcdef");
		data->len += ft_numlen(num) + 2;
	}
	else if (*format == 'x' || *format == 'c')
		ft_parse_helper2(format, data, args);
	else
		return (NULL);
	format++;
	return (format);
}

const char	*ft_parse(const char *format, t_data *data, va_list args)
{
	int		num;
	char	*str;

	if (*format == 'd')
	{
		num = va_arg(args, int);
		ft_putnbr(num);
		data->len += ft_numlen(num);
	}
	else if (*format == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		data->len += ft_strlen(str);
		ft_putstr(str);
	}
	else if (*format == 'x' || *format == 'X' || *format == 'p'
		|| *format == 'c')
		ft_parse_helper(format, data, args);
	else
		return (NULL);
	format++;
	return (format);
}

const char	*ft_write_text(const char *format, t_data *data)
{
	char	*next;

	next = ft_strchr(format);
	if (next)
		data->written = next - format;
	else
		data->written = ft_strlen(format);
	write(1, format, data->written);
	data->len += data->written;
	return (format + data->written);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_data	data;

	data.len = 0;
	data.written = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format = ft_parse(format + 1, &data, args);
		}
		else
		{
			format = ft_write_text(format, &data);
		}
		if (!format)
		{
			write(1, "(null)", 6);
			va_end(args);
			return (data.written);
		}
	}
	va_end(args);
	return (data.written);
}
