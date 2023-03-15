/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:53:26 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/15 13:53:28 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ft.h"

void ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

int main(int argc, char **argv)
{
    int i;
    int *fd;
    int offset;
    int len;
    char *buf;

    fd = malloc(sizeof(int) * 16);
    buf = malloc(16 * sizeof(char));
    i = 1;
    offset = 0;
    if (argc == 1)
        write(1, "File name missing.\n", 19);
    while (i < argc)
    {
        *fd = open(argv[i], O_RDONLY);
        if (*fd == -1)
        {
            ft_putstr("hexdump: ");
            ft_putstr(argv[i]);
            ft_putstr(": ");
            ft_putstr(strerror(errno));
            ft_putstr("\n");
        }
        else
        {
            while ((len = read(*fd, buf, 16)) > 0)
            {
                ft_hexdump(*fd, offset, buf, len);
                offset += len;
            }
            close(*fd);
        }
        i++;
    }
    return (0);
}
*/