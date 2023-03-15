/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:17:03 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/14 16:46:23 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
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

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	ft_tail(int *fd, int n, char *buf, int len)
{
	int	i;
	int	j;
	int	k;

	buf = malloc(sizeof(char) * n);
	if (!buf)
		return ;
	i = 0;
	len = 0;
	while (read(*fd, &buf[i], 1) != 0)
	{
		if (len < n)
			len++;
		i = (i + 1) % n;
	}
	j = i;
	k = (i + len) % n;
	if (j < k)
		write(1, &buf[j], k - j);
	else
	{
		write(1, &buf[j], n - j);
		write(1, &buf[0], k);
	}
	free(buf);
}

int	main(int ac, char **av)
{
	int		i;
	int		fd;
	char	*buf;
	int		len;

	len = 0;
	buf = NULL;
	i = 3;
	if (ac > 2)
	{
		if (av[1][0] == '-' && av[1][1] == 'c')
		{
			while (av[i])
			{
				fd = open(av[i], O_RDONLY);
				ft_tail(&fd, ft_atoi(av[2]), buf, len);
				i++;
			}
		}
	}
	else
		ft_putstr("usage: ft_tail [-c #] [file ...]\n");
	return (0);
}
