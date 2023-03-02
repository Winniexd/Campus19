/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 10:10:00 by mdreesen          #+#    #+#             */
/*   Updated: 2023/02/25 15:52:13 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);

void	print_firstline_helper(int i, int j, int w)
{
	if (j == 0)
	{
		ft_putchar('A');
	}
	if (j == w - 1 && w > 1)
	{
		ft_putchar('C');
	}
	else if (j > 0 && j < w - 1)
	{
		ft_putchar('B');
	}
}

void	print_firstline(int w, int h)
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
				print_firstline_helper(i, j, w);
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
				ft_putchar('B');
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

void	print_lastline(int w, int h)
{
	int	j;

	j = 0;
	while (j < w)
	{
		if (j == 0)
		{
			ft_putchar('A');
		}
		if (j == w - 1 && w > 1)
		{
			ft_putchar('C');
		}
		else if (j > 0 && j < w - 1)
		{
			ft_putchar('B');
		}
		j++;
	}
	ft_putchar('\n');
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
		print_firstline(w, h);
	}
	else
	{
		print_firstline(w, h);
		print_middlelines(w, h);
		print_lastline(w, h);
	}
}
