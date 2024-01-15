/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:57:38 by matias            #+#    #+#             */
/*   Updated: 2024/01/15 13:50:19 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_radix_sort_b(t_ps *ps)
{
	int	size;

	size = ps_lstsize(ps->stack_b);
	while (size--)
		ps_push_a(&ps->stack_a, &ps->stack_b);
}

void	ps_radix_sort(t_ps *ps)
{
	int	bit_size;
	int	i;
	int	size;

	bit_size = 1;
	size = ps->size;
	while (size > 1 && bit_size++)
		size /= 2;
	i = 0;
	while (i <= bit_size)
	{
		size = ps->size;
		while (size-- && !ps_is_sorted(ps->stack_a))
		{
			if (((ps->stack_a->pos >> i) & 1) == 0)
				ps_push_b(&ps->stack_a, &ps->stack_b);
			else
				ps_rotate_a(ps);
		}
		ps_radix_sort_b(ps);
		i++;
	}
}
