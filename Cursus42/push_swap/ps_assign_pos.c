/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_assign_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:36:05 by matias            #+#    #+#             */
/*   Updated: 2023/11/30 11:39:04 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list *get_next_min(t_list **stack)
{
    t_list *head;
    t_list *min;
    int has_min;

    min = NULL;
    has_min = 0;
    head = *stack;

    if (head)
    {
        while (head)
        {
            if ((head->index == -1) && (!has_min || head->value < min->value))
            {
                min = head;
                has_min = 1;
            }
            head = head->next;
        }
    }

    return (min);
}


void	ps_assign_pos(t_list **stack)
{
	t_list	*head;
	int		pos;

	pos = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->pos = pos++;
		head = get_next_min(stack);
	}
}
