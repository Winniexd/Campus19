/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jepatern <jepatern@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/20 19:30:43 by matias			#+#	#+#			 */
/*   Updated: 2024/12/11 14:28:57 by jepatern		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press(int keycode, t_cub3d *comet)
{
	if (keycode == ESC)
		comet->keys.esc = ft_clean_exit(comet, 0);
	else if (keycode == 100)
		comet->keys.forward = 1;
	else if (keycode == 97)
		comet->keys.backward = 1;
	else if (keycode == 119)
		comet->keys.left = 1;
	else if (keycode == 115)
		comet->keys.right = 1;
	else if (keycode == 65361 || keycode == 113)
		comet->keys.rotate_left = 1;
	else if (keycode == 65363 || keycode == 101)
		comet->keys.rotate_right = 1;
	return (0);
}

int	ft_key_release(int keycode, t_cub3d *comet)
{
	if (keycode == ESC)
		comet->keys.esc = 0;
	else if (keycode == 100)
		comet->keys.forward = 0;
	else if (keycode == 97)
		comet->keys.backward = 0;
	else if (keycode == 119)
		comet->keys.left = 0;
	else if (keycode == 115)
		comet->keys.right = 0;
	else if (keycode == 65361 || keycode == 113)
		comet->keys.rotate_left = 0;
	else if (keycode == 65363 || keycode == 101)
		comet->keys.rotate_right = 0;
	return (0);
}

int	ft_game_loop(t_cub3d *comet)
{
	ft_key_hook(comet);
	ft_gen_frame(comet);
	return (0);
}

void	ft_init_keys(t_cub3d *comet)
{
	comet->keys.esc = 0;
	comet->keys.forward = 0;
	comet->keys.backward = 0;
	comet->keys.left = 0;
	comet->keys.right = 0;
	comet->keys.rotate_left = 0;
	comet->keys.rotate_right = 0;
}

int	main(int argc, char **argv)
{
	t_cub3d	comet;

	ft_init_keys(&comet);
	if (argc != 2)
		return (ft_write_err("Wrong number of arguments", NULL));
	if (ft_init_cub3d(&comet, argv[1]))
		ft_clean_exit(&comet, 1);
	ft_init_mlx(&comet);
	mlx_hook(comet.win, 2, 1L << 0, ft_key_press, &comet);
	mlx_hook(comet.win, 3, 1L << 1, ft_key_release, &comet);
	mlx_hook(comet.win, 17, 1L << 0, ft_clean_exit, &comet);
	mlx_loop_hook(comet.mlx, ft_game_loop, &comet);
	mlx_loop(comet.mlx);
	ft_clean_exit(&comet, 0);
	return (0);
}
