/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:08:08 by matias            #+#    #+#             */
/*   Updated: 2024/02/13 11:30:31 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_valid_move(char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		return (1);
	if (ft_strcmp(line, "sb\n") == 0)
		return (1);
	if (ft_strcmp(line, "ss\n") == 0)
		return (1);
	if (ft_strcmp(line, "pa\n") == 0)
		return (1);
	if (ft_strcmp(line, "pb\n") == 0)
		return (1);
	if (ft_strcmp(line, "ra\n") == 0)
		return (1);
	if (ft_strcmp(line, "rb\n") == 0)
		return (1);
	if (ft_strcmp(line, "rr\n") == 0)
		return (1);
	if (ft_strcmp(line, "rra\n") == 0)
		return (1);
	if (ft_strcmp(line, "rrb\n") == 0)
		return (1);
	if (ft_strcmp(line, "rrr\n") == 0)
		return (1);
	return (0);
}

void	ps_execute_simultaneous(t_ps *ps, char *line)
{
	if (ft_strcmp(line, "ss\n") == 0)
	{
		ps_swap(&ps->stack_a);
		ps_swap(&ps->stack_b);
	}
	if (ft_strcmp(line, "rr\n") == 0)
	{
		ps_rotate(&ps->stack_a);
		ps_rotate(&ps->stack_b);
	}
	if (ft_strcmp(line, "rrr\n") == 0)
	{
		ps_reverse_rotate(&ps->stack_a);
		ps_reverse_rotate(&ps->stack_b);
	}
}

void	ps_execute(t_ps *ps, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		ps_swap(&ps->stack_a);
	if (ft_strcmp(line, "sb\n") == 0)
		ps_swap(&ps->stack_b);
	if (ft_strcmp(line, "pa\n") == 0)
		ps_push(&ps->stack_a, &ps->stack_b);
	if (ft_strcmp(line, "pb\n") == 0)
		ps_push(&ps->stack_b, &ps->stack_a);
	if (ft_strcmp(line, "ra\n") == 0)
		ps_rotate(&ps->stack_a);
	if (ft_strcmp(line, "rb\n") == 0)
		ps_rotate(&ps->stack_b);
	if (ft_strcmp(line, "rra\n") == 0)
		ps_reverse_rotate(&ps->stack_a);
	if (ft_strcmp(line, "rrb\n") == 0)
		ps_reverse_rotate(&ps->stack_b);
	ps_execute_simultaneous(ps, line);
}

int	ps_main_loop(t_ps *ps)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!ps_valid_move(line))
		{
			ps_free_stacks(ps->stack_a, ps->stack_b);
			free(ps);
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
		ps_execute(ps, line);
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2)
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ps = malloc(sizeof(t_ps));
	if (!ps)
		return (0);
	if (!ps_create_stack(&ps->stack_a, argv, argc))
	{
		ps_free_stacks(ps->stack_a, NULL);
		free(ps);
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	if (!ps_main_loop(ps))
		return (0);
	if (ps_is_sorted(ps->stack_a) && !ps->stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ps_free_stacks(ps->stack_a, ps->stack_b);
	free(ps);
	return (0);
}
