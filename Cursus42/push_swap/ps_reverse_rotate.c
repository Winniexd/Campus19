/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:03:08 by marvin            #+#    #+#             */
/*   Updated: 2023/11/13 17:03:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_reverse_rotate(t_node **head)
{
    *head = (*head)->prev;
}

void ps_reverse_rotate_a(t_ps *ps)
{
    ps_reverse_rotate(&ps->stack_a);
    write(1, "rra\n", 4);
}

void ps_reverse_rotate_b(t_ps *ps)
{
    ps_reverse_rotate(&ps->stack_b);
    write(1, "rrb\n", 4);
}

void ps_reverse_rotate_r(t_ps *ps)
{
    ps_reverse_rotate(&ps->stack_a);
    ps_reverse_rotate(&ps->stack_b);
    write(1, "rrr\n", 4);
}
