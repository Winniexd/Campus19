/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_assign_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:34:29 by matias            #+#    #+#             */
/*   Updated: 2024/01/07 16:21:40 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ps_find_next_smallest(t_node **head)
{
    int smallest = INT_MAX;
    t_node *tmp = *head;

    while (1)
    {
        if (tmp->val < smallest && tmp->pos == 0)
            smallest = tmp->val;
        tmp = tmp->next;
        if (tmp == *head)
            break;
    }

    return (smallest);
}

void ps_assign_pos(t_node **head)
{
    int i = 1;
    int size = ps_lstsize(*head);
    t_node *tmp = *head;

    while (i <= size)
    {
        int smallest = ps_find_next_smallest(head);
        
        while (1)
        {
            if (tmp->val == smallest && tmp->pos == 0)
                tmp->pos = i;
            tmp = tmp->next;
            if (tmp == *head)
                break;
        }
        tmp = *head;
        i++;
    } 
}
