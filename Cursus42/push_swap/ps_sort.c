/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:49:42 by mdreesen          #+#    #+#             */
/*   Updated: 2023/10/10 11:48:34 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_sort(t_ps *ps)
{
    if (ps->size == 2)
        ps_sort_two(ps);
    else if (ps->size == 3)
        ps_sort_three(ps);
        /*
    else if (ps->size == 4)
        ps_sort_four(ps);
    else if (ps->size == 5)
        ps_sort_five(ps);
    else
        ps_sort_big(ps);
        */
}
