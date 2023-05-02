/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:16:32 by mdreesen          #+#    #+#             */
/*   Updated: 2023/05/02 10:16:33 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
    printf("printf: %u\n", -1);
    ft_printf("ft_printf: %u\n", -1);
    printf("%d\n", printf("printf: %u\n", -1));
    printf("%d\n", ft_printf("ft_printf: %u\n", -1));
    printf("printf: %i\n", -1);
    ft_printf("ft_printf: %i\n", -1);
    printf("%d\n", printf("printf: %i\n", -1));
    printf("%d\n", ft_printf("ft_printf: %i\n", -1));
    return (0);
}