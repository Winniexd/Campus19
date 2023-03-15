/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:32:45 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/15 17:54:47 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *ft_strdup(char *src)
{
    char *dest;
    int i;

    i = 0;
    while (src[i] != '\0')
        i++;
    dest = (char *)malloc(sizeof(char) * (i + 1));
    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void ft_display_error(char *str)
{
    write(1, "hexdump: ", 9);
    write(1, str, strlen(str));
    write(1, ": ", 2);
    write(1, strerror(errno), strlen(strerror(errno)));
    write(1, "\n", 1);
}

void ft_offset(int offset)
{
    char *hex;
    int i;

    hex = "0123456789abcdef";
    i = 7;
    while (i >= 0)
    {
        write(1, &hex[(offset >> (i * 4)) & 0xf], 1);
        i--;
    }
}

void ft_print_hex(char *buf, int len)
{
    int i;
    char *hex;

    hex = "0123456789abcdef";
    i = 0;
    while (i < len)
    {
        write(1, &hex[(buf[i] >> 4) & 0xf], 1);
        write(1, &hex[buf[i] & 0xf], 1);
        write(1, " ", 1);
        if (i == 7)
            write(1, " ", 1);
        i++;
    }
    while (i < 16)
    {
        write(1, "   ", 3);
        if (i == 7)
            write(1, " ", 1);
        i++;
    }
}

void ft_print_char(char *buf, int len)
{
    int i;

    i = 0;
    write(1, " |", 2);
    while (i < len)
    {
        if (buf[i] >= 32 && buf[i] <= 126)
            write(1, &buf[i], 1);
        else
            write(1, ".", 1);
        i++;
    }
    write(1, "|\n", 2);
}

void ft_hexdump(int *fd, char *buf)
{
    int offset;
    int len;
    char *prev_buff;

    prev_buff = malloc(16 * sizeof(char));
    offset = 0;
    while ((len = read(*fd, buf, 16)) > 0)
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
        offset += 16;
        if (len < 16)
        {
            ft_offset(offset - 16 + len);
            write(1, "\n", 1);
        }
        prev_buff = ft_strdup(buf);
    }
}

void ft_proces(int i, char **av)
{
    int fd;
    char *buf;

    buf = malloc(16 * sizeof(char));
    fd = open(av[i], O_RDONLY);
    if (fd == -1)
    {
        ft_display_error(av[i]);
    }
    else
    {
        ft_hexdump(&fd, buf);
        close(fd);
    }
}

int main(int ac, char **av)
{
    int i;

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
