/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:17:03 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/16 18:01:58 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
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
	int		last_char_index;

	buf = malloc(sizeof(char) * n);
	if (!buf)
		return ;
	len = read(*fd, buf, n);
	if (len == -1)
	{
		ft_putstr("tail: ");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
	}
	while (len)
	{
		last_char_index = len - 1;
		if (buf[last_char_index] != '\n')
		{
			buf[last_char_index + 1] = '\n';
			len++;
		}
		write(1, buf, len);
		len = read(*fd, buf, n);
	}
	free(buf);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	ft_tail(int *fd, int n, char *buf, int len)
{
	int	i;
	int	k;

	if (!buf)
		return ;
	i = 0;
	len = 0;
	while (read(*fd, &buf[i], 1) > 0)
	{
		if (len < n)
			len++;
		i = (i + 1) % n;
	}
	buf[len] = '\0';
	k = (i + len) % n;
	if (n > len)
		ft_putstr(buf);
	else if (i < k)
		write(1, &buf[i], k - i);
	else
	{
		write(1, &buf[i], n - i);
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
	if (bytes_read == -1)
		return (-1);
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
