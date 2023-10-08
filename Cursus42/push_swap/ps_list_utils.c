/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:33:45 by marvin            #+#    #+#             */
/*   Updated: 2023/10/07 14:33:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ps_lstadd_back(t_node **head, int nbr)
{
    t_node *new;

    new = malloc(sizeof(t_node));
    if (!new)
        return (0);
    new->value = nbr;
    if (!(*head))
    {
        new->next = new;
        new->prev = new;
        *head = new;
    }
    else
    {
        new->next = *head;
        new->prev = (*head)->prev;
        (*head)->prev->next = new;
        (*head)->prev = new;
    }
    return (1);
}

size_t ps_lstsize(t_node *head)
{
    size_t size;
    t_node *tmp;

    size = 0;
    tmp = head;
    if (!head)
        return (0);
    while (tmp->next != head)
    {
        size++;
        tmp = tmp->next;
    }
    return (size + 1);
}

int ps_has_dups(t_node **head)
{
    t_node *tmp;
    t_node *tmp2;

    tmp = *head;
    while (tmp->next != *head)
    {
        tmp2 = tmp->next;
        while (tmp2 != *head)
        {
            if (tmp->value == tmp2->value)
                return (1);
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
    return (0);
}

int ps_is_sorted(t_node *head)
{
    t_node *tmp;

    tmp = head;
    while (tmp->next != head)
    {
        if (tmp->value > tmp->next->value)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}
