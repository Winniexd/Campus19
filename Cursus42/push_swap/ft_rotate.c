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

void	ft_rotate(t_stack *stack)
{
    int tmp;
    int i;

    i = 0;
    if (stack->size > 1)
    {
        tmp = stack->tab[0];
        while (i < stack->size - 1)
        {
            stack->tab[i] = stack->tab[i + 1];
            i++;
        }
        stack->tab[i] = tmp;
    }
}

void    ft_rotate_a(t_stack *stack_a)
{
    ft_rotate(stack_a);
    ft_putstr("ra\n");
}

void    ft_rotate_b(t_stack *stack_b)
{
    ft_rotate(stack_b);
    ft_putstr("rb\n");
}

void    ft_rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
    ft_rotate(stack_a);
    ft_rotate(stack_b);
    ft_putstr("rr\n");
}