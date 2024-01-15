/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:49:42 by mdreesen          #+#    #+#             */
/*   Updated: 2024/01/08 13:33:04 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort(t_ps *ps)
{
	if (ps->size == 2)
		ps_sort_two(ps);
	else if (ps->size == 3)
		ps_sort_three(ps);
	else
		ps_radix_sort(ps);
}
