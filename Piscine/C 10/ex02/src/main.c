/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:04:18 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/16 08:15:21 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <fcntl.h>
#include <stdlib.h>

void	process(int ac, char **av, int i, char *buf)
{
	int	fd;
	int	len;

	len = 0;
	if (ac > 2)
	{
		if (av[1][0] == '-' && av[1][1] == 'c')
		{
			while (av[i])
			{
				fd = open(av[i], O_RDONLY);
				if (check_n_bigger_than_file(av[i], ft_atoi(av[2])))
					ft_tail(&fd, ft_atoi(av[2]), buf, len);
				else
					display_file(&fd, ft_atoi(av[2]), len);
				i++;
			}
		}
	}
	else
		ft_putstr("usage: ft_tail [-c #] [file ...]\n");
}

int	main(int ac, char **av)
{
	int		i;
	char	*buf;

	buf = NULL;
	i = 3;
	process(ac, av, i, buf);
	return (0);
}
