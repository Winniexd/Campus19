/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:23:58 by matias            #+#    #+#             */
/*   Updated: 2023/09/26 16:50:30 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_create_stack(t_ps **stack_a, char **argv, int argc)
{
    int nbr;
    int i;

    while (i < argc)
    {
        nbr = ft_atoi(argv[i++]);
        if (!(ft_isdigit(nbr)))
            return 0;
        ps_lstadd_back(stack_a, nbr);
    }
    return 1;
}