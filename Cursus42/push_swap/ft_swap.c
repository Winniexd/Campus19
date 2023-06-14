/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:15:28 by mdreesen          #+#    #+#             */
/*   Updated: 2023/05/24 11:15:29 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node *stack)
{
    int tmp;

    if (stack && stack->next)
    {
        tmp = stack->value;
        stack->value = stack->next->value;
        stack->next->value = tmp;
    }
}

void    ft_swap_a(t_node *stack_a)
{
    ft_swap(stack_a);
    ft_putstr("sa\n");
}

void    ft_swap_b(t_node *stack_b)
{
    ft_swap(stack_b);
    ft_putstr("sb\n");
}

void    ft_swap_ss(t_node *stack_a, t_node *stack_b)
{
    ft_swap(stack_a);
    ft_swap(stack_b);
    ft_putstr("ss\n");
}