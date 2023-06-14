/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:01:12 by mdreesen          #+#    #+#             */
/*   Updated: 2023/05/24 12:01:13 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_node **stack)
{
    t_node *tmp;

    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
}

void	ft_free_tab(char **argv, int argc)
{
    int i;

    i = 0;
    while (i < argc)
    {
        free(argv[i]);
        i++;
    }
    free(argv);
}

void    ft_free_error(t_node **stack, char **argv, int argc)
{
    ft_free_stack(stack);
    ft_free_tab(argv, argc);
    ft_putstr("Error\n");
    exit(0);
}