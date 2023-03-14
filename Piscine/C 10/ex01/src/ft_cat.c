/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:55:51 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/14 14:47:54 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_cat(int fd)
{
	int		ret;
	int		size;
	char	buf[32];

	size = 32;
	ret = read(fd, buf, size);
	while (ret > 0)
	{
		buf[ret] = '\0';
		ft_putstr(buf);
		ret = read(fd, buf, size);
	}
	if (ret == -1)
	{
		ft_putstr("cat: ");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
	}
	else
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	fd;

	i = 1;
	{
		while (i < ac)
		{
			fd = open(av[i], O_RDONLY);
			if (fd == -1)
			{
				ft_putstr("cat: ");
				ft_putstr(av[i]);
				ft_putstr(": ");
				ft_putstr(strerror(errno));
				ft_putstr("\n");
			}
			else
			{
				ft_cat(fd);
				close(fd);
			}
			i++;
		}
	}
	return (0);
}
