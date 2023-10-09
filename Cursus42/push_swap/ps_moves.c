/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:01:15 by mdreesen          #+#    #+#             */
/*   Updated: 2023/10/09 15:04:07 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_rotate(t_node **head)
{
    *head = (*head)->next;
}

void ps_reverse_rotate(t_node **head)
{
    *head = (*head)->prev;
}

void ps_swap(t_node **head)
{}

void ps_push(t_node **src_head, t_node **dst_head)
{}