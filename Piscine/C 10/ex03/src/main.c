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

#include "../includes/ft.h"

void	yolo(char *buf, int len, char *prev_buff, int offset)
{
	if (ft_strcmp(prev_buff, buf))
	{
		ft_offset(offset);
		write(1, "  ", 2);
		ft_print_hex(buf, len);
		ft_print_char(buf, len);
	}
	else
		write(1, "*\n", 2);
}

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
