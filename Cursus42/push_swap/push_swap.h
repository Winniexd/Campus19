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
# include <limits.h>

typedef struct s_node
{
    int     value;
    int     index;
    struct s_node *next;
    struct s_node *prev;
}					t_node;

void    ft_swap(t_node *stack);
void    ft_swap_a(t_node *stack_a);
void    ft_swap_b(t_node *stack_b);
void    ft_swap_ss(t_node *stack_a, t_node *stack_b);
void    ft_push(t_node **stack_a, t_node **stack_b);
void    ft_push_a(t_node **stack_a, t_node **stack_b);
void    ft_push_b(t_node **stack_a, t_node **stack_b);
void    ft_rotate(t_node *stack);
void    ft_rotate_a(t_node *stack_a);
void    ft_rotate_b(t_node *stack_b);
void    ft_rotate_rr(t_node *stack_a, t_node *stack_b);
void    ft_reverse_rotate(t_node *stack);
void    ft_reverse_rotate_a(t_node *stack_a);
void    ft_reverse_rotate_b(t_node *stack_b);
void    ft_reverse_rotate_rrr(t_node *stack_a, t_node *stack_b);
void    ft_putstr(char *str);
void    ft_create_stack(t_node **stack, char **argv, int argc);
int		ft_check_duplicates(int argc, char **argv);
void    ft_sort_three(t_node *stack);
void    ft_free_stack(t_node **stack);
void    ft_free_error(t_node **stack, char **argv, int argc);

#endif