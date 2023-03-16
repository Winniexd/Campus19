/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:04:18 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/16 20:19:26 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_display_error(int error, char *str)
{
	ft_putstr(str);
	ft_putstr(": ");
	ft_putstr(strerror(error));
	ft_putstr("\n");
}

void	process(int ac, char **av, int i, char *buf)
{
	int	fd;
	int	len;
	int	error;

	len = 0;
	(void)ac;
	fd = 0;
	if (av[1][0] == '-' && av[1][1] == 'c')
	{
		while (ac > i && av[i])
		{
			error = check_n_bigger_than_file(av[i], ft_atoi(av[2]));
			fd = open(av[i], O_RDONLY);
			if (fd == -1)
				ft_display_error(errno, av[i]);
			else if (error == 1)
				ft_tail(&fd, ft_atoi(av[2]), buf, len);
			else if (error == 0)
				display_file(&fd, ft_atoi(av[2]), len);
			else
				ft_display_error(errno, av[i]);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	int		i;
	char	*buf;
	int		fd;
	int		len;

	len = 0;
	buf = malloc(sizeof(char) * ft_atoi(av[2]));
	if (ac > 3)
	{
		i = 3;
		process(ac, av, i, buf);
	}
	if (ac == 3)
	{
		fd = 0;
		if (check_n_bigger_than_file(av[i], ft_atoi(av[2])))
			ft_tail(&fd, ft_atoi(av[2]), buf, len);
		else
			display_file(&fd, ft_atoi(av[2]), len);
	}
	return (0);
}
