/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:00:17 by mdreesen          #+#    #+#             */
/*   Updated: 2023/05/24 12:00:17 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_create_node(t_node **stack, int number)
{
    t_node *node;
    t_node *prev_node;

    if (stack == NULL)
        return;
    node = (t_node *)malloc(sizeof(t_node));
    if (node == NULL)
        return;
    node->next = NULL;
    node->value = number;
    if (*stack == NULL)
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        prev_node = *stack;
        while (prev_node->next != NULL)
            prev_node = prev_node->next;
        prev_node->next = node;
        node->prev = prev_node;
    }
}

void   ft_create_stack(t_node **stack, char **argv, int argc)
{
    int i;
    int number;

    i = 0;
    while (argv[i])
    {
        number = ft_atoi(argv[i]);
        if (ft_check_duplicates(argc, argv) == 0)
        {
            ft_free_error(stack, argv, argc);
            ft_putstr("Error\n");
            exit(0);
        }
        ft_create_node(stack, number);
        i++;
    }
    if (argc == 1)
        ft_free_error(stack, argv, argc);
}
