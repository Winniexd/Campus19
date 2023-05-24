/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:07:01 by mdreesen          #+#    #+#             */
/*   Updated: 2023/05/24 12:07:02 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *stack_a, t_stack *stack_b)
{
    int i;

    i = stack_a->size - 1;
    while (i > 0)
    {
        stack_a->tab[i] = stack_a->tab[i - 1];
        i--;
    }
    stack_a->tab[0] = stack_b->tab[0];
    i = 0;
    while (i < stack_b->size - 1)
    {
        stack_b->tab[i] = stack_b->tab[i + 1];
        i++;
    }
    stack_b->tab[i] = 0;
}

void    ft_push_a(t_stack *stack_a, t_stack *stack_b)
{
    ft_push(stack_a, stack_b);
    ft_putstr("pa\n");
}

void    ft_push_b(t_stack *stack_a, t_stack *stack_b)
{
    ft_push(stack_b, stack_a);
    ft_putstr("pb\n");
}