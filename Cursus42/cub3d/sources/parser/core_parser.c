/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:00:13 by matias            #+#    #+#             */
/*   Updated: 2024/12/12 17:08:04 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// Calls different functions for extracting data
// according to the first character in that line
int	extract_data(t_cub3d *c, char **buffer, int i, int j)
{
	while (ft_is_white_char(buffer[i][j]))
		j++;
	if (ft_isalpha(buffer[i][j]))
	{
		if (buffer[i][j + 1] && ft_isalpha(buffer[i][j + 1]))
		{
			if (ft_fill_directions(&c->config, buffer[i], j))
				return (ft_write_err("Invalid direction or duplicate", buffer[i]));
			return (BREAK);
		}
		else
		{
			if (ft_fill_colors(&c->config, buffer[i], j))
				return (ft_write_err("Invalid color", NULL));
			return (BREAK);
		}
	}
	else if (ft_isdigit(buffer[i][j]))
	{
		if (ft_fill_map(c, buffer, i))
			return (KO);
		return (OK);
	}
	return (CONTINUE);
}

// Goes through config->file and calls the extract_data function for every line
int	ft_parse_config(t_cub3d *c, char **buffer)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j])
		{
			ret = extract_data(c, buffer, i, j);
			if (ret == BREAK)
				break ;
			else if (ret == KO)
				return (KO);
			else if (ret == OK)
				return (OK);
			j++;
		}
		i++;
	}
	return (OK);
}
