/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:49:42 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/13 10:42:13 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort(t_ps *ps)
{
	if (ps_is_sorted(ps->stack_a))
		return ;
	if (ps->size == 2)
		ps_sort_two(ps);
	else if (ps->size == 3)
		ps_sort_three(ps);
	else if (ps->size == 4)
		ps_sort_four(ps);
	else if (ps->size == 5)
		ps_sort_five(ps);
	else
		ps_radix_sort(ps);
}
