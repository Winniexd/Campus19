/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:02:48 by marvin            #+#    #+#             */
/*   Updated: 2024/01/09 15:42:18 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push_2(t_node **head_dest, t_node **head_src, t_node *temp)
{
	if (*head_dest)
	{
		(*head_src)->next = *head_dest;
		(*head_src)->prev = (*head_dest)->prev;
		(*head_src)->prev->next = *head_src;
		(*head_src)->next->prev = *head_src;
	}
	else
	{
		(*head_src)->next = *head_src;
		(*head_src)->prev = *head_src;
	}
	*head_dest = *head_src;
	*head_src = temp;
}

int	ps_push(t_node **head_dest, t_node **head_src)
{
	t_node	*temp;

	temp = 0;
	if (!(*head_src))
		return (0);
	if (*head_src != (*head_src)->next)
	{
		(*head_src)->prev->next = (*head_src)->next;
		(*head_src)->next->prev = (*head_src)->prev;
		temp = (*head_src)->prev->next;
	}
	else
		temp = 0;
	ps_push_2(head_dest, head_src, temp);
	return (1);
}

void ps_push_a(t_node **head_a, t_node **head_b)
{
    ps_push(head_a, head_b);
    write(1, "pa\n", 3);
}

void ps_push_b(t_node **head_a, t_node **head_b)
{
    ps_push(head_b, head_a);
    write(1, "pb\n", 3);
}
