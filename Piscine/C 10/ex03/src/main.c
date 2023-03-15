/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:53:26 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/15 20:41:10 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_proces(int i, char **av)
{
	int		fd;
	char	*buf;
	int		offset;

	offset = 0;
	buf = malloc(16 * sizeof(char));
	fd = open(av[i], O_RDONLY);
	if (fd == -1)
	{
		ft_display_error(av[i]);
	}
	else
	{
		ft_hexdump(&fd, buf, offset);
		close(fd);
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 2;
	if (av[1][0] == '-' && av[1][1] == 'C')
	{
		while (i < ac)
		{
			ft_proces(i, av);
			i++;
		}
	}
	return (0);
}
