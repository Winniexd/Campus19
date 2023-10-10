/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:11:01 by mdreesen          #+#    #+#             */
/*   Updated: 2023/10/10 14:48:29 by mdreesen         ###   ########.fr       */
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
    int value;
    int pos;
    int endpos;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_ps
{
    t_node *stack_a;
    t_node *stack_b;
    int  size;
} t_ps;

int ps_lstadd_back(t_node **head, int nbr);
int ps_lstsize(t_node *head);
int ps_is_sorted(t_node *head);
int ps_has_dups(t_node *head);
int ps_create_stack(t_node **head_a, char **argv, int argc);
int ps_valid(const char *s);
void ps_assign_pos(t_node *head);

#endif