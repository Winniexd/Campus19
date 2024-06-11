/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:01:36 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/11 14:41:24 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "minilibx-linux/mlx.h"

//Macros
#define WIDTH 960
#define HEIGHT 720
#define ESC 65307

typedef struct s_cub3d {
    void *mlx;
    void *win;
    struct s_mlx *m;
}   t_cub3d;

int write_err(char *err, int retval);
void init_mlx(t_cub3d *c);
int free_mlx(t_cub3d *c);
int key_hook(int key, t_cub3d *c);

#endif