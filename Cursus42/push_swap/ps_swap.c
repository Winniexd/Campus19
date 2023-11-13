/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:01:15 by mdreesen          #+#    #+#             */
/*   Updated: 2023/10/10 11:48:08 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_swap(t_node **head)
{
    t_node *tmp;

    tmp = *head;
    *head = (*head)->next;
    tmp->next = (*head)->next;
    (*head)->next = tmp;
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
