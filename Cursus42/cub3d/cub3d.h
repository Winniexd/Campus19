/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:01:36 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/28 15:42:58 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "minilibx-linux/mlx.h"
#include "gnl/get_next_line.h"

//Macros
#define WIDTH 960
#define HEIGHT 720
#define ESC 65307
#define NO 0
#define EA 1
#define SO 2
#define WE 3
#define F 4
#define C 5

typedef struct s_config {
	int data[6];
}	t_config;

typedef struct s_cub3d {
    void *mlx;
    void *win;
	t_config config;
}   t_cub3d;

int write_err(char *err, int retval);
void init_mlx(t_cub3d *c);
void init_map(t_cub3d *c, char *path);
int free_mlx(t_cub3d *c);
int key_hook(int key, t_cub3d *c);
int ft_suffix(char *path, char *suffix);
char **ft_split(char const *s, char c);

#endif