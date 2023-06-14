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

void	ft_sort_three(t_node *stack)
{
    int a;
    int b;
    int c;

    a = stack->value;
    b = stack->next->value;
    c = stack->next->next->value;
    if (a > b && b < c && a < c)
        ft_swap(stack);
    else if (a > b && b > c && a > c)
    {
        ft_swap(stack);
        ft_rotate(stack);
    }
    else if (a > b && b < c && a > c)
        ft_reverse_rotate(stack);
    else if (a < b && b > c && a < c)
    {
        ft_swap(stack);
        ft_reverse_rotate(stack);
    }
    else if (a < b && b > c && a > c)
        ft_rotate(stack);
}