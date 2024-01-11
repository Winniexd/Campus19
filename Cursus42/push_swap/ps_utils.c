/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:08:04 by mdreesen          #+#    #+#             */
/*   Updated: 2024/01/11 14:54:07 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ps_valid(const char *s)
{
    int i;
    int minus;
    
    minus = 1;
    i = 0;
    while (s[i])
    {
        if (s[i] == '-' && minus)
        {
            minus = 0;
            i++;
        }
        if (!ft_isdigit(s[i]))
            return(0);
        i++;
    }
    return (1);
}

int ps_return_smallest(t_node **head)
{
    t_node *tmp;
    int smallest;
    
    tmp = (*head)->next;
    smallest = tmp->val;
    while (tmp != *head)
    {
        if (tmp->val < smallest)
            smallest = tmp->val;
        tmp = tmp->next;
    }
    return (smallest);
}

int ps_return_biggest(t_node **head)
{
    t_node *tmp;
    int biggest;
    
    tmp = (*head)->next;
    biggest = tmp->val;
    while (tmp != *head)
    {
        if (tmp->val > biggest)
            biggest = tmp->val;
        tmp = tmp->next;
    }
    return (biggest);
}