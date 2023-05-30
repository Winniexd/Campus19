/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:11:01 by mdreesen          #+#    #+#             */
/*   Updated: 2023/05/24 11:11:14 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
    int    size;
    int    *tab;
}					t_stack;

void    ft_swap(t_stack *stack);
void    ft_swap_a(t_stack *stack_a);
void    ft_swap_b(t_stack *stack_b);
void    ft_swap_ss(t_stack *stack_a, t_stack *stack_b);
void    ft_push(t_stack *stack_a, t_stack *stack_b);
void    ft_push_a(t_stack *stack_a, t_stack *stack_b);
void    ft_push_b(t_stack *stack_a, t_stack *stack_b);
void    ft_rotate(t_stack *stack);
void    ft_rotate_a(t_stack *stack_a);
void    ft_rotate_b(t_stack *stack_b);
void    ft_rotate_rr(t_stack *stack_a, t_stack *stack_b);
void    ft_reverse_rotate(t_stack *stack);
void    ft_reverse_rotate_a(t_stack *stack_a);
void    ft_reverse_rotate_b(t_stack *stack_b);
void    ft_reverse_rotate_rrr(t_stack *stack_a, t_stack *stack_b);
t_stack *ft_create_stack(int size);
void    ft_free_stack(t_stack *stack);
int     ft_is_sorted(t_stack *stack);
int     ft_fill_stack_a(t_stack *stack_a, int argc, char **argv);
int     ft_check_duplicates(int argc, char **argv);
void    ft_sort(t_stack *stack_a, t_stack *stack_b);
void    ft_putstr(char *str);

#endif