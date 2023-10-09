/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:11:01 by mdreesen          #+#    #+#             */
/*   Updated: 2023/09/26 16:51:01 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "Libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_node
{
    int value;
    int index;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_ps
{
    t_node *stack_a;
    t_node *stack_b;
    size_t  size;
} t_ps;

int ps_lstadd_back(t_node **head, int nbr);
size_t ps_lstsize(t_node *head);
int ps_is_sorted(t_node *head);
int ps_has_dups(t_node **head);

#endif