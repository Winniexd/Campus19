/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:33:47 by mdreesen          #+#    #+#             */
/*   Updated: 2023/05/24 11:33:48 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_node *stack)
{
    t_node *tmp;

    if (stack && stack->next)
    {
        tmp = stack;
        stack = stack->next;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = stack;
        tmp->next->prev = tmp;
        tmp->next->next->prev = NULL;
        tmp->next->next = NULL;
    }
}

void    ft_rotate_a(t_node *stack_a)
{
    ft_rotate(stack_a);
    ft_putstr("ra\n");
}

void    ft_rotate_b(t_node *stack_b)
{
    ft_rotate(stack_b);
    ft_putstr("rb\n");
}

void    ft_rotate_rr(t_node *stack_a, t_node *stack_b)
{
    ft_rotate(stack_a);
    ft_rotate(stack_b);
    ft_putstr("rr\n");
}