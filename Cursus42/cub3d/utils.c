/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:17:45 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/11 14:40:01 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int write_err(char *err, int retval)
{
    printf("%s\n", err);
    return retval;
}

int key_hook(int key, t_cub3d *c)
{
    if (key == ESC)
        free_mlx(c);
    return 0;
}