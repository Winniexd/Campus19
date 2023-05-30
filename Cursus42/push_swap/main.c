/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:18:50 by mdreesen          #+#    #+#             */
/*   Updated: 2023/05/24 11:18:51 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
        return (ft_putstr_fd("Error\n", STDERR_FILENO));
    stack_a = ft_create_stack(argc - 1);
    stack_b = ft_create_stack(argc - 1);
    if (stack_a == NULL || stack_b == NULL)
        return (ft_putstr_fd("Error\n", STDERR_FILENO));
    if (ft_check_duplicates(argc, argv) == 0)
        return (ft_putstr_fd("Error\n", STDERR_FILENO));
    ft_fill_stack_a(stack_a, argc, argv);
    ft_sort(stack_a, stack_b);
    //print stacks
    for (int i = 0; i < stack_a->size; i++)
    {
        printf("%d ", stack_a->tab[i]);
        printf("%d\n", stack_b->tab[i]);
    }
    printf("%d\n", stack_a->size);
    ft_free_stack(stack_a);
    ft_free_stack(stack_b);
    return (0);
}