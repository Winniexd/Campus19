/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:28:01 by mdreesen          #+#    #+#             */
/*   Updated: 2023/05/24 11:28:02 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_error(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        if (argv[i][j] == '-')
            j++;
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j]) == 0)
            {
                ft_putstr("Error\n");
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}