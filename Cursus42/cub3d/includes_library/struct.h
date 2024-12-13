/* ************************************************************************** */
/*																			  */
/*														:::	  ::::::::        */
/*   struct.h										   :+:	  :+:	:+:       */
/*													+:+ +:+		 +:+	      */
/*   By: jepatern <jepatern@student.42.fr>		  +#+  +:+	   +#+		      */
/*												+#+#+#+#+#+   +#+		      */
/*   Created: 2024/12/04 19:02:22 by jepatern		  #+#	#+#			      */
/*   Updated: 2024/12/04 19:04:30 by jepatern		 ###   ########.fr	      */
/*																			  */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_config
{
	int			fd;
	char		*north;
	char		*east;
	char		*south;
	char		*west;
	int			*floor;
	int			*ceiling;
	int			floor_trgb;
	int			ceiling_trgb;
	char		**file;
	char		**map;
	int			height;
	int			width;
	double		play_xy[2];
	double		dir_xy[2];
}				t_config;

typedef struct s_img
{
	void		*mlx;
	void		*mlx_img;
	void		*addr;
	int			bpp;
	int			height;
	int			width;
	int			length;
	int			endian;
}				t_img;

typedef struct s_frame
{
	char		*raw;
	char		*addr;
	int			bpp;
	int			length;
	int			endian;
}				t_frame;

typedef struct s_keys
{
	int			forward;
	int			backward;
	int			left;
	int			right;
	int			rotate_left;
	int			rotate_right;
	int			esc;
}				t_keys;

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	t_config	config;
	t_img		img[4];
	t_keys		keys;
}				t_cub3d;

typedef struct s_ray_data
{
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit_side;
	double		ddx;
	double		ddy;
	double		side_dist_x;
	double		side_dist_y;
}				t_rdata;

typedef struct s_r
{
	char		wall_dir;
	double		w_x;
	double		d;
	double		distance;
	char		obj;
}				t_r;

typedef struct s_d
{
	int	h;		// line height
	int	start;	// draw start
	int	end;	// draw end
	int	t_x;	// texture x position
}				t_d;

typedef struct s_rc
{
	double	fov;		// field of view
	double	d_angle;	// delta angle
	double	offset;	// angle offset
	double	dir_x;	// ray direction X
	double	dir_y;	// ray direction Y
}				t_rc;

#endif