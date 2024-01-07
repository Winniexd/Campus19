/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:17:27 by matias            #+#    #+#             */
/*   Updated: 2024/01/07 16:07:15 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void display_stacks(t_node *head)
{
    t_node *tmp;
    tmp = head->next;
    printf("%d\n", head->pos);
    while (tmp != head)
    {
        printf("%d\n", tmp->pos);
        tmp = tmp->next;
    }
}

int main(int argc, char **argv)
{
    t_ps *ps;
    
    ps = malloc(sizeof(t_ps));
    if (!ps)
        return (0);
    if (!ps_create_stack(&ps->stack_a, argv, argc))
    {
        ft_putstr_fd("Error\n", 1);
        return (0);
    }
    ps->size = ps_lstsize(ps->stack_a);
    ps_sort(ps);
    display_stacks(ps->stack_a);
    //printf("size: %d\n", ps->size);
    
    return (0);
}