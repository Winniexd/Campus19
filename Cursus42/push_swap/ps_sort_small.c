/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:49:05 by marvin            #+#    #+#             */
/*   Updated: 2024/01/19 15:09:38 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_do_rotation(t_ps *ps, int i)
{
	int	size;

	if (i == 0)
		return ;
	size = ps_lstsize(ps->stack_a);
	if (i <= size / 2)
		while (i--)
			ps_rotate_a(ps);
	else
		while (i++ < size)
			ps_reverse_rotate_a(ps);
}

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

void	ps_sort_four(t_ps *ps)
{
	int		i;
	int		smallest;
	t_node	*tmp;

	smallest = ps_return_smallest(&ps->stack_a);
	i = 0;
	tmp = ps->stack_a;
	while (tmp->val != smallest)
	{
		i++;
		tmp = tmp->next;
	}
	ps_do_rotation(ps, i);
	ps_push_b(&ps->stack_a, &ps->stack_b);
	ps_sort_three(ps);
	ps_push_a(&ps->stack_a, &ps->stack_b);
}

void	ps_sort_five(t_ps *ps)
{
	int		i;
	int		smallest;
	t_node	*tmp;

	smallest = ps_return_smallest(&ps->stack_a);
	i = 0;
	tmp = ps->stack_a;
	while (tmp->val != smallest)
	{
		i++;
		tmp = tmp->next;
	}
	ps_do_rotation(ps, i);
	ps_push_b(&ps->stack_a, &ps->stack_b);
	ps_sort_four(ps);
	ps_push_a(&ps->stack_a, &ps->stack_b);
}
