/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:03:24 by marvin            #+#    #+#             */
/*   Updated: 2024/01/15 13:49:00 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rotate(t_node **head)
{
	*head = (*head)->next;
}

void	ps_rotate_a(t_ps *ps)
{
	ps_rotate(&ps->stack_a);
	write(1, "ra\n", 3);
}

void	ps_rotate_b(t_ps *ps)
{
	ps_rotate(&ps->stack_b);
	write(1, "rb\n", 3);
}

void	ps_rotate_r(t_ps *ps)
{
	ps_rotate(&ps->stack_a);
	ps_rotate(&ps->stack_b);
	write(1, "rr\n", 3);
}
