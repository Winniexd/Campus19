/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:17:27 by matias            #+#    #+#             */
/*   Updated: 2023/09/12 16:23:26 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    ps->size = ps_lstsize(&ps->stack_a);
    ps_sort(ps);
    return (0);
}