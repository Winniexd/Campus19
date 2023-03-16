/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:17:03 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/15 20:44:00 by mdreesen         ###   ########.fr       */
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

void	display_file(int *fd, int n, int len)
{
	char	*buf;

	buf = malloc(sizeof(char) * n);
	if (!buf)
		return ;
	len = read(*fd, buf, n);
	while (len)
	{
		write(1, buf, len);
		len = read(*fd, buf, n);
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

int	check_n_bigger_than_file(char *av, int n)
{
	char	buf[4096];
	int		bytes_read;
	int		total_bytes_read;
	int		fd;

	fd = open(av, O_RDONLY);
	bytes_read = 0;
	total_bytes_read = 0;
	bytes_read = read(fd, buf, sizeof(buf));
	while (bytes_read > 0)
	{
		total_bytes_read += bytes_read;
		bytes_read = read(fd, buf, sizeof(buf));
		if (total_bytes_read >= n)
			return (1);
	}
	if (bytes_read == 0 && total_bytes_read >= n)
		return (1);
	return (0);
}
