/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matias <matias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:01:36 by mdreesen          #+#    #+#             */
/*   Updated: 2024/08/27 10:43:06 by matias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

// Macros
# define WIDTH 960
# define HEIGHT 720
# define ESC 65307
# define BREAK -1
# define OK 0
# define KO 1
# define CONTINUE 2
# define NO 0
# define EA 1
# define SO 2
# define WE 3
# define F 4
# define C 5

typedef struct s_map
{
	char		**map;
}				t_map;

typedef struct s_config
{
	int			map_started;
	int			fd;
	int			floor[3];
	int			ceiling[3];
	char		xpm_path[4];
}				t_config;

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	char		*addr;
	t_config	config;
	t_map		map;
}				t_cub3d;

// Hooks
int				key_hook(int key, t_cub3d *c);

// Init
void			init_mlx(t_cub3d *c);
int				init_cub3d(t_cub3d *c, char *path);

// Parsing
int				parse_config(t_cub3d *c, char **map);

// Utils
int				clean_exit(t_cub3d *c, int code);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_suffix(char *path, char *suffix);
int				write_err(char *err, int retval);
int				get_line_count(char *path);
int             ft_ischar(char c);

#endif