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

int ft_is_sorted(t_stack *stack)
{
    int i;

    i = 0;
    while (i < stack->size - 1)
    {
        if (stack->tab[i] > stack->tab[i + 1])
            return (0);
        i++;
    }
    return (1);
}

int ft_search_min(t_stack *stack_a)
{
    int i;
    int min;

    i = 0;
    min = stack_a->tab[0];
    if (stack_a->size == 1)
        return (min);
    while (i < stack_a->size)
    {
        if (stack_a->tab[i] < min)
        {
            min = stack_a->tab[i];
        }
        i++;
    }
    return (min);
}

void ft_push_min(t_stack *stack_a, t_stack *stack_b)
{
    int min;
    
    min = ft_search_min(stack_a);
    while (stack_a->tab[0] != min)
    {
        ft_rotate_a(stack_a);
    }
    ft_push_b(stack_a, stack_b);
}

void ft_sort(t_stack *stack_a, t_stack *stack_b)
{
    int i;

    i = 0;
    if (ft_is_sorted(stack_a) == 1)
        return ;
    while (stack_a->size)
    {
        ft_push_min(stack_a, stack_b);
    }
    while (i < stack_b->size)
    {
        ft_push_a(stack_a, stack_b);
        i++;
    }
}
