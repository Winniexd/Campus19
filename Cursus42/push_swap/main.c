/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:17:27 by matias            #+#    #+#             */
/*   Updated: 2024/02/20 12:08:51 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free_argv(char **argv)
{
	char **tmp;

	tmp = argv;
	while (*argv)
	{
		free(*argv);
		argv++;
	}
	free(tmp);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2 || !ft_strcmp(argv[1], ""))
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!argv)
		return (1);
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
	ps->size = ps_lstsize(ps->stack_a);
	ps_sort(ps);
	ps_free_stacks(ps->stack_a, ps->stack_b);
	if (argc == 2)
		ps_free_argv(argv);
	free(ps);
	return (0);
}
