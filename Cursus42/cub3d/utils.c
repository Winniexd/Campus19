/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:36:42 by matias            #+#    #+#             */
/*   Updated: 2024/07/24 15:13:25 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int write_err(char *err, int retval) {
    write(1, err, ft_strlen(err));
    return (retval);
}

int get_line_count(char *path)
{
    int fd;
    int linecount;
    char *line;

    fd = open(path, O_RDONLY);
    line = get_next_line(fd);
    linecount = 0;
    while (line)
    {
        linecount++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return linecount;
}

int ft_strcmp(const char *s1, const char *s2)
{
    size_t i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int ft_suffix(char *path, char *suffix)
{
    int i;
    int j;

    i = ft_strlen(path) - 1;
    j = ft_strlen(suffix) - 1;
    while (j >= 0) {
        if (path[i] != suffix[j])
            return (1);
        i--;
        j--;
    }
    return (0);
}
