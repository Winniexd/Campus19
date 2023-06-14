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

void    ft_reverse_rotate(t_node *stack)
{
    t_node *tmp;

    if (stack && stack->next)
    {
        tmp = stack;
        while (tmp->next)
            tmp = tmp->next;
        tmp->prev->next = NULL;
        tmp->prev = NULL;
        tmp->next = stack;
        stack->prev = tmp;
    }
}

void    ft_reverse_rotate_a(t_node *stack_a)
{
    ft_reverse_rotate(stack_a);
    ft_putstr("rra\n");
}

void    ft_reverse_rotate_b(t_node *stack_b)
{
    ft_reverse_rotate(stack_b);
    ft_putstr("rrb\n");
}

void    ft_reverse_rotate_rrr(t_node *stack_a, t_node *stack_b)
{
    ft_reverse_rotate(stack_a);
    ft_reverse_rotate(stack_b);
    ft_putstr("rrr\n");
}