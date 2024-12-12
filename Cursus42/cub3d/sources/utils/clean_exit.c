/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:54:32 by matias            #+#    #+#             */
/*   Updated: 2024/12/12 17:22:34 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_write_err(char *err, char *arg)
{
	if (!err)
		return (1);
	printf("Error: %s", err);
	if (arg)
		printf(": %s", arg);
	printf("\n");
	return (1);
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_config(t_config *c)
{
	if (c->file)
		ft_free_arr(c->file);
	if (c->fd > 0)
		close(c->fd);
	if (c->north)
		free(c->north);
	if (c->east)
		free(c->east);
	if (c->south)
		free(c->south);
	if (c->west)
		free(c->west);
	if (c->ceiling)
		free(c->ceiling);
	if (c->floor)
		free(c->floor);
}

void	free_map(t_config *m)
{
	int	i;

	i = 0;
	if (m->map)
	{
		while (m->map[i] != NULL)
		{
			free(m->map[i]);
			i++;
		}
		free(m->map);
	}
}

int	ft_clean_exit(t_cub3d *c, int code)
{
	if (!c)
		exit(code);
	free_config(&c->config);
	free_map(&c->config);
	if (c->mlx)
	{
		mlx_clear_window(c->mlx, c->win);
		mlx_destroy_window(c->mlx, c->win);
		mlx_destroy_display(c->mlx);
		mlx_loop_end(c->mlx);
		free(c->mlx);
	}
	exit(1);
}
