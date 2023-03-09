/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:27:59 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/09 14:05:24 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	ft_read(int file_descriptor)
{
	char	buffer[100];
	int		total_bytes_read;
	int		bytes_read;

	total_bytes_read = 0;
	bytes_read = 0;
	while (1)
	{
		bytes_read = read(file_descriptor, buffer, sizeof(buffer));
		if (bytes_read == -1)
		{
			write(2, "Cannot read file\n", 17);
			close(file_descriptor);
			return (1);
		}
		if (bytes_read == 0)
			break ;
		write(1, buffer, bytes_read);
		total_bytes_read += bytes_read;
	}
	close(file_descriptor);
	return (0);
}

int	main(int ac, char **av)
{
	int	file_descriptor;

	if (ac == 2)
	{
		file_descriptor = open(av[1], O_RDONLY);
		if (file_descriptor == -1)
		{
			write(1, "Cannot read file\n", 17);
			return (0);
		}
		ft_read(file_descriptor);
	}
	else if (ac > 2)
	{
		write(2, "Too many arguments\n", 19);
		return (1);
	}
	return (0);
}
