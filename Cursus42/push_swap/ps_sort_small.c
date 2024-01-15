/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:49:05 by marvin            #+#    #+#             */
/*   Updated: 2024/01/15 13:45:31 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_two(t_ps *ps)
{
	if (ps->stack_a->val > ps->stack_a->next->val)
		ps_swap_a(ps);
}

void	ps_sort_three(t_ps *ps)
{
	if (ps_is_sorted(ps->stack_a))
		return ;
	else if (ps->stack_a->val > ps->stack_a->next->val)
		ps_swap_a(ps);
	else if (ps->stack_a->val > ps->stack_a->prev->val)
		ps_reverse_rotate_a(ps);
	else
		ps_reverse_rotate_a(ps);
	ps_sort_three(ps);
}
