/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:01:15 by mdreesen          #+#    #+#             */
/*   Updated: 2023/11/18 14:37:50 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_swap(t_node **head)
{
    if ((*head)->next->next == *head)
        ps_rotate(head);
    else
    {
        (*head)->prev->next = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        (*head)->next = (*head)->next->next;
        (*head)->next->prev = *head;
        (*head)->prev->next->next = *head;
        (*head)->prev = (*head)->prev->next;
        *head = (*head)->prev;
    }
}

void ps_swap_a(t_ps *ps)
{
    ps_swap(&ps->stack_a);
    write(1, "sa\n", 3);
}

void ps_swap_b(t_ps *ps)
{
    ps_swap(&ps->stack_b);
    write(1, "sb\n", 3);
}

void ps_swap_s(t_ps *ps)
{
    ps_swap(&ps->stack_a);
    ps_swap(&ps->stack_b);
    write(1, "ss\n", 3);
}
