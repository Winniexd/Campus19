/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:30:00 by mdreesen          #+#    #+#             */
/*   Updated: 2023/05/24 11:30:01 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_sorted(t_stack *stack_a)
{
    int i;

    i = 0;
    while (i < stack_a->size - 1)
    {
        if (stack_a->tab[i] > stack_a->tab[i + 1])
            return (0);
        i++;
    }
    return (1);
}

void ft_sort(t_stack *stack_a, t_stack *stack_b)
{
    if (ft_is_sorted(stack_a))
        return;

    while (!ft_is_sorted(stack_a))
    {
        if (stack_a->tab[0] > stack_a->tab[1])
            ft_swap_a(stack_a);
        else if (stack_a->tab[0] > stack_a->tab[stack_a->size - 1] ||
                 stack_a->tab[stack_a->size - 1] < stack_a->tab[1])
            ft_reverse_rotate_a(stack_a);
        else if (stack_a->tab[0] < stack_a->tab[1])
            ft_push_b(stack_a, stack_b);
        else
            ft_rotate_a(stack_a);
    }
}
