/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:00:13 by matias            #+#    #+#             */
/*   Updated: 2024/07/24 15:11:07 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int find_key(char *line)
{
    (void)line;
    return 1;
}

int parse_config(t_config *conf, char *path)
{
    int fd;
    char *line;
    int key;

    fd = open(path, O_RDONLY);
    line = get_next_line(fd);
    while (line && !(conf->map_started))
    {
        key = find_key(line);
        if (!ft_strcmp(line, "F") && !ft_strcmp(line, "C"))
            return 0;
        (void)key;
    }
    return 1;
}