/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 10:10:00 by mdreesen          #+#    #+#             */
/*   Updated: 2023/02/25 14:22:16 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);

void	print_horizontal(int w, int h)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < h)
	{
		while (j < w)
		{
			if (i == 0)
			{
				if (j == 0 || j == w - 1)
				{
					ft_putchar('o');
				}
				else
				{
					ft_putchar('-');
				}
			}
			j++;
		}
		i++;
	}
	ft_putchar('\n');
}

void	print_middlelines(int w, int h)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < h - 1)
	{
		j = 0;
		while (j < w)
		{
			if (j == 0 || j == w - 1)
			{
				ft_putchar('|');
			}
			else
			{
				ft_putchar(' ');
			}
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

void	rush(int w, int h)
{
	if (h < 0 || w < 0)
	{
		printf("Dimensions must be bigger than 0!\n");
		return ;
	}
	else if (h == 1)
	{
		print_horizontal(w, h);
	}
	else
	{
		print_horizontal(w, h);
		print_middlelines(w, h);
		print_horizontal(w, h);
	}
}
