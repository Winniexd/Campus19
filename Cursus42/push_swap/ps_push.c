/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:02:48 by marvin            #+#    #+#             */
/*   Updated: 2023/11/13 17:02:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_push(t_node **src_head, t_node **dst_head)
{
    t_node *tmp;

    tmp = *src_head;
    *src_head = (*src_head)->next;
    tmp->next = *dst_head;
    *dst_head = tmp;
}

void ps_push_a(t_ps *ps)
{
    ps_push(&ps->stack_b, &ps->stack_a);
    write(1, "pa\n", 3);
}

void ps_push_b(t_ps *ps)
{
    ps_push(&ps->stack_a, &ps->stack_b);
    write(1, "pb\n", 3);
}
