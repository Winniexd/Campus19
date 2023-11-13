/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:49:05 by marvin            #+#    #+#             */
/*   Updated: 2023/10/18 13:49:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_sort_two(t_ps *ps)
{
    if (ps->stack_a->val > ps->stack_a->next->val)
        ps_swap(&ps->stack_a);
}

void ps_sort_three(t_ps *ps)
{
    if (ps->stack_a->val > ps->stack_a->next->val && ps->stack_a->val < ps->stack_a->next->next->val)
        ps_rotate(&ps->stack_a);
    else if (ps->stack_a->val > ps->stack_a->next->val && ps->stack_a->val > ps->stack_a->next->next->val)
    {
        ps_swap(&ps->stack_a);
        ps_rotate(&ps->stack_a);
    }
    else if (ps->stack_a->val > ps->stack_a->next->val && ps->stack_a->val > ps->stack_a->next->next->val)
    {
        ps_swap(&ps->stack_a);
        ps_rotate(&ps->stack_a);
    }
    else if (ps->stack_a->val < ps->stack_a->next->val && ps->stack_a->val > ps->stack_a->next->next->val)
    {
        ps_reverse_rotate(&ps->stack_a);
    }
    else if (ps->stack_a->val < ps->stack_a->next->val && ps->stack_a->val < ps->stack_a->next->next->val)
    {
        ps_swap(&ps->stack_a);
        ps_reverse_rotate(&ps->stack_a);
    }
}