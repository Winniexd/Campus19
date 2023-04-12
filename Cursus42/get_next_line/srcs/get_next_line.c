/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:45:00 by mdreesen          #+#    #+#             */
/*   Updated: 2023/04/12 14:45:01 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

#define BUFFER_SIZE 1

char *get_next_line(int fd)
{
    char *line;
    static char *prev_buffer = NULL;
    char *buffer;
    int ret;

    if (prev_buffer == NULL)
        prev_buffer = malloc(sizeof(char) * BUFFER_SIZE);
    buffer = malloc(sizeof(char) * BUFFER_SIZE);
    line = malloc(sizeof(char) * BUFFER_SIZE);
    line[0] = '\0';
    if (prev_buffer[0] != '\0')
        line = ft_strjoin(line, prev_buffer);
    ret = read(fd, buffer, BUFFER_SIZE);
    while (ret > 0)
    {
        if (ft_strchr(buffer, '\n'))
        {
            line = ft_strjoin(line, buffer);
            free(prev_buffer);
            prev_buffer = NULL;
            return (line);
        }
        line = ft_strjoin(line, buffer);
        ret = read(fd, buffer, BUFFER_SIZE);
    }
    if (ret == 0 && line[0] == '\0')
    {
        free(prev_buffer);
        prev_buffer = NULL;
        free(buffer);
        return (NULL);
    }
    free(prev_buffer);
    prev_buffer = ft_strdup(buffer);
    free(buffer);
    return (line);
}

int main()
{
    int fd;

    fd = open("test.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    return (0);
}