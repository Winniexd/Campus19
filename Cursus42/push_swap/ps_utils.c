/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:08:04 by mdreesen          #+#    #+#             */
/*   Updated: 2023/10/10 14:47:33 by mdreesen         ###   ########.fr       */
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

void ps_assign_pos(t_node *head)
{
    int pos;
    t_node *tmp;

    pos = 1;
    head->pos = 0;
    tmp = head->next;
    while (tmp != head)
    {
        tmp->pos = pos++;
        tmp = tmp->next;
    }
}