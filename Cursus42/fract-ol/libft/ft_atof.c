/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:12:09 by winniexd          #+#    #+#             */
/*   Updated: 2023/06/15 14:12:30 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_atof2(const char *str, double res, int sign)
{
    int		i;
    double	dec;

    i = 0;
    dec = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i++] - '0');
    }
    if (str[i] == '.')
    {
        i++;
        while (str[i] >= '0' && str[i] <= '9')
        {
            dec = dec * 10 + (str[i++] - '0');
        }
    }
    return (sign * (res + dec / 10));
}

double			ft_atof(const char *str)
{
    int		i;
    double	res;
    int		sign;

    i = 0;
    res = 0;
    sign = 1;
    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
            str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-')
        sign = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    return (ft_atof2(str + i, res, sign));
}