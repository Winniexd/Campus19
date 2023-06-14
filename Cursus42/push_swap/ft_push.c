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

void ft_push(t_node **stack_src, t_node **stack_dst)
{
    t_node *tmp;

    if (*stack_src)
    {
        tmp = *stack_src;
        *stack_src = (*stack_src)->next;
        tmp->next = *stack_dst;
        *stack_dst = tmp;
    }
}

void ft_push_a(t_node **stack_a, t_node **stack_b)
{
    ft_push(stack_b, stack_a);
    ft_putstr("pa\n");
}

void ft_push_b(t_node **stack_a, t_node **stack_b)
{
    ft_push(stack_a, stack_b);
    ft_putstr("pb\n");
}
