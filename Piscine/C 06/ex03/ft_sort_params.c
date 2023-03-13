/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:50:21 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/06 15:32:53 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort(char **av, int ac)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			k = 0;
			while (av[i][k] == av[j][k])
			{
				if (av[i][k] == '\0')
					break ;
				k++;
			}
			if (av[i][k] > av[j][k])
				ft_swap(&av[i], &av[j]);
			j++;
		}
		i++;
	}
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	int	i;

	ft_sort(av, ac);
	i = 1;
	while (i < ac)
		ft_putstr(av[i++]);
	return (0);
}
