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

int		ft_check_duplicates(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 1;
        while (j < argc)
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]) && i != j)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
