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

void	ft_swap(t_node **head)
{
    t_node *tmp;

    if (!(*head) || !(*head)->next)
        return ;
    tmp = *head;
    *head = (*head)->next;
    tmp->next = (*head)->next;
    (*head)->next = tmp;
}

void	ft_swap_both(t_ps *ps)
{
    ft_swap(&ps->stack_a);
    ft_swap(&ps->stack_b);
    write(1, "ss\n", 3);
}

void	ft_swap_a(t_ps *ps)
{
    ft_swap(&ps->stack_a);
    write(1, "sa\n", 3);
}

void	ft_swap_b(t_ps *ps)
{
    ft_swap(&ps->stack_b);
    write(1, "sb\n", 3);
}