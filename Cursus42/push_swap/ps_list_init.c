/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:57:13 by marvin            #+#    #+#             */
/*   Updated: 2024/02/20 12:11:01 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_create_stack(t_node **head_a, char **argv, int argc)
{
	int	i;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		if (!ps_valid(argv[i]) || !ps_lstadd_back(head_a, ps_atoi(argv[i])))
			return (0);
		i++;
	}
	if (argc > 2)
		if (ps_lstsize(*head_a) != argc - 1)
			return (0);
	if (ps_has_dups(*head_a))
		return (0);
	ps_assign_pos(head_a);
	return (1);
}
