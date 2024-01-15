/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:11:01 by mdreesen          #+#    #+#             */
/*   Updated: 2024/01/15 13:35:00 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_node
{
    int val;
    int pos;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_ps
{
    t_node *stack_a;
    t_node *stack_b;
    int size;
} t_ps;

// Utils
int ps_lstadd_back(t_node **head, int nbr);
int ps_lstsize(t_node *head);
int ps_is_sorted(t_node *head);
int ps_has_dups(t_node *head);
int ps_create_stack(t_node **head_a, char **argv, int argc);
int ps_valid(const char *s);
void ps_assign_pos(t_node **head);
int ps_return_biggest(t_node **head);
int ps_return_smallest(t_node **head);
void ps_free_stacks(t_node *head_a, t_node *head_b);

// Moves
void ps_swap(t_node **head);
void ps_swap_a(t_ps *ps);
void ps_swap_b(t_ps *ps);
void ps_swap_s(t_ps *ps);
int ps_push(t_node **src_head, t_node **dst_head);
void ps_push_a(t_node **head_a, t_node **head_b);
void ps_push_b(t_node **head_a, t_node **head_b);
void ps_rotate(t_node **head);
void ps_rotate_a(t_ps *ps);
void ps_rotate_b(t_ps *ps);
void ps_rotate_r(t_ps *ps);
void ps_reverse_rotate(t_node **head);
void ps_reverse_rotate_a(t_ps *ps);
void ps_reverse_rotate_b(t_ps *ps);
void ps_reverse_rotate_r(t_ps *ps);

// Sort
void ps_sort(t_ps *ps);
void ps_sort_two(t_ps *ps);
void ps_sort_three(t_ps *ps);
void ps_sort_four(t_ps *ps);
void ps_sort_five(t_ps *ps);
void ps_radix_sort(t_ps *ps);

#endif