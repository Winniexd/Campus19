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

t_stack		*ft_create_stack(int size)
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (stack == NULL)
        return (NULL);
    stack->tab = (int *)malloc(sizeof(int) * size);
    if (stack->tab == NULL)
        return (NULL);
    stack->size = size;
    return (stack);
}