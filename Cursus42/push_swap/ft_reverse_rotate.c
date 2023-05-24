/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:34:39 by mdreesen          #+#    #+#             */
/*   Updated: 2023/05/24 11:34:40 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_reverse_rotate(t_stack *stack)
{
    int tmp;
    int i;

    i = stack->size - 1;
    if (stack->size > 1)
    {
        tmp = stack->tab[i];
        while (i > 0)
        {
            stack->tab[i] = stack->tab[i - 1];
            i--;
        }
        stack->tab[i] = tmp;
    }
}

void    ft_reverse_rotate_a(t_stack *stack_a)
{
    ft_reverse_rotate(stack_a);
    ft_putstr("rra\n");
}

void    ft_reverse_rotate_b(t_stack *stack_b)
{
    ft_reverse_rotate(stack_b);
    ft_putstr("rrb\n");
}

void    ft_reverse_rotate_rrr(t_stack *stack_a, t_stack *stack_b)
{
    ft_reverse_rotate(stack_a);
    ft_reverse_rotate(stack_b);
    ft_putstr("rrr\n");
}