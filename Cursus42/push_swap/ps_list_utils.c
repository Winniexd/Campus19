/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:33:45 by marvin            #+#    #+#             */
/*   Updated: 2024/01/07 14:49:50 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ps_lstadd_back(t_node **head, int nbr)
{
    t_node *new;

    new = malloc(sizeof(t_node));
    if (!new)
        return (0);
    new->val = nbr;
    new->pos = 0;
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

int ps_lstsize(t_node *head)
{
    int size;
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

int ps_has_dups(t_node *head)
{
    t_node *tmp;
    t_node *tmp2;

    tmp = head;
    while (tmp->next != head)
    {
        tmp2 = tmp->next;
        while (tmp2 != head)
        {
            if (tmp->val == tmp2->val)
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
        if (tmp->val > tmp->next->val)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

void ps_add_front(t_node **head, int nbr)
{
    t_node *new;

    new = malloc(sizeof(t_node));
    if (!new)
        return ;
    new->val = nbr;
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
        *head = new;
    }
}