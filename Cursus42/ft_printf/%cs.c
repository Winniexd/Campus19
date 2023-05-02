/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %cs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:04:52 by mdreesen          #+#    #+#             */
/*   Updated: 2023/05/02 14:04:53 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void handle_percent(t_data *data)
{
    ft_putchar('%');
    data->len++;
}

void handle_char(t_data *data, va_list args)
{
    char c;

    c = va_arg(args, int);
    ft_putchar(c);
    data->len++;
}

void handle_string(t_data *data, va_list args)
{
    char *str;

    str = va_arg(args, char *);
    if (str == NULL)
        str = "(null)";
    ft_putstr(str);
    data->len += ft_strlen(str);
}