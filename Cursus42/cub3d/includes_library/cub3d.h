/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:01:36 by mdreesen          #+#    #+#             */
/*   Updated: 2024/12/11 14:15:41 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "include.h"
# include "macro.h"
# include "struct.h"

// Init
void	ft_init_mlx(t_cub3d *c);
int		ft_init_cub3d(t_cub3d *c, char *path);
void	struct_bzero(t_cub3d *c);

// Parsing
int		check_map(t_config *config);
int		ft_parse_config(t_cub3d *c, char **map);
int		ft_fill_colors(t_config *config, char *line, int j);
int		ft_fill_directions(t_config *config, char *line, int j);
int		ft_fill_map(t_cub3d *c, char **buffer, int i);
int		ft_parse_xpm(t_img *img, char *path);
int     check_file(char *path, int is_cub);

// Utils
int		ft_clean_exit(t_cub3d *c, int code);
int		ft_suffix(char *path, char *suffix);
int		ft_write_err(char *err, char *line);
int		ft_get_line_count(char *path);
int		ft_ischar(char c);
void	ft_free_arr(char **tab);
char	*ft_get_path(char *line, int j);
int		ft_is_white_char(char c);
void	ft_display_config(t_config *config);
double	ft_degrees_to_radians(double degrees);
int		create_trgb(int t, int r, int g, int b);
int		ft_choose(char *str, char x);

// Executive part
void	ft_calculate_ray(double *pxy, t_rc *rc, t_rdata *ray_info, t_r *rdata);
void	ft_init_rdata(double *pxy, double dir_x, double dir_y, t_rdata *rdata);
void	ft_find_wall(t_rdata *ray_info, char **map);
void	ft_cast_ray(double *pxy, t_rc *rc, char **map, t_r *rdata);
void	ft_create_base_image(t_cub3d *c, t_frame *img);
void	ft_draw_frame(t_cub3d *c, t_frame *frame, t_r *ray_data, t_rc *rc);
void	ft_vertical_slice(t_frame *img, t_img *texture, int col, t_r *ray_data);
void	ft_gen_frame(t_cub3d *comet);
int		ft_key_hook(int key, t_cub3d *comet);
void	rotate_player(double *dirX, double *dirY, double angle);
void	ft_px_put(t_frame *img, int x, int y, int color);

#endif