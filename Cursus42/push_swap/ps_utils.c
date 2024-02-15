/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:08:04 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/13 10:53:37 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_valid(const char *s)
{
	int	i;
	int	minus;

	minus = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == '-' && minus)
		{
			minus = 0;
			i++;
		}
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ps_return_smallest(t_node **head)
{
	t_node	*tmp;
	int		smallest;

	tmp = (*head)->next;
	smallest = (*head)->val;
	while (tmp != *head)
	{
		if (tmp->val < smallest)
			smallest = tmp->val;
		tmp = tmp->next;
	}
	return (smallest);
}

int	ps_return_biggest(t_node **head)
{
	t_node	*tmp;
	int		biggest;

	tmp = (*head)->next;
	biggest = (*head)->val;
	while (tmp != *head)
	{
		if (tmp->val > biggest)
			biggest = tmp->val;
		tmp = tmp->next;
	}
	return (biggest);
}

int	ps_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (nb > INT_MAX || nb < INT_MIN)
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	return (nb * sign);
}
