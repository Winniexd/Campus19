/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:57:13 by marvin            #+#    #+#             */
/*   Updated: 2023/10/07 14:57:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ps_create_stack(t_node **head, char **argv, int argc)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (!ps_lstadd_back(head, ft_atoi(argv[i])))
            return (0);
        i++;
    }
    if (ps_has_dups(head) || ps_lstsize(*head) != argc - 1)
        return (0);
    return (1);
}