/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xXp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:13:34 by mdreesen          #+#    #+#             */
/*   Updated: 2023/05/02 12:13:35 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    if (s1 == NULL || s2 == NULL)
        return (NULL);
    str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (str == NULL)
        return (NULL);
    while (s1[i] != '\0')
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0')
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    return (str);
}

void handle_x(t_data *data, va_list args)
{
    unsigned int nbr;

    nbr = va_arg(args, unsigned int);
    data->len += ft_putnbr_base(nbr, "0123456789abcdef");
}

void handle_X(t_data *data, va_list args)
{
    unsigned int nbr;

    nbr = va_arg(args, unsigned int);
    data->len += ft_putnbr_base(nbr, "0123456789ABCDEF");
}

void handle_p(t_data *data, va_list args)
{
    unsigned long nbr;

    nbr = va_arg(args, unsigned long);
    if (nbr == 0)
    {
        ft_putstr("(nil)");
        data->len += 5;
    }
    else
    {
        ft_putstr("0x");
        data->len += 2;
        data->len += ft_putnbr_base(nbr, "0123456789abcdef");
    }
}