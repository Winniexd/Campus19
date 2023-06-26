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

const char	*ft_handle_flags(const char *format, t_data *data, va_list args)
{
	if (*format == 'p')
		handle_p(data, args);
	else if (*format == 'x')
		handle_x(data, args);
	else if (*format == 'X')
		handle_cx(data, args);
	else if (*format == 'd' || *format == 'i')
		handle_int(data, args);
	else if (*format == 'u')
		handle_unsigned_int(data, args);
	else if (*format == '%')
		handle_percent(data);
	else if (*format == 'c')
		handle_char(data, args);
	else if (*format == 's')
		handle_string(data, args);
	else
		return (NULL);
	return (format + 1);
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
			format = ft_handle_flags(format + 1, &data, args);
		}
		else
		{
			format = ft_write_text(format, &data);
		}
		if (!format)
		{
			write(1, "(null)", 6);
			va_end(args);
			return (data.len);
		}
	}
	va_end(args);
	return (data.len);
}
