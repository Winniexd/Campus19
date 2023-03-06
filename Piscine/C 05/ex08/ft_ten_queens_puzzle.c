/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:53:55 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/06 22:58:33 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_is_safe(char solution[11], int col, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (solution[i] - '0' == col || ft_abs(solution[i] - '0'
				- col) == ft_abs(i - row))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_solve_ten_queens(char solution[11], int row)
{
	int	col;

	if (row == 10)
	{
		write(1, solution, 11);
		write(1, "\n", 1);
		return ;
	}
	col = 0;
	while (col < 10)
	{
		if (ft_is_safe(solution, col, row))
		{
			solution[row] = col + '0';
			ft_solve_ten_queens(solution, row + 1);
			solution[row] = '\0';
		}
		col++;
	}
}

void	ft_ten_queens_puzzle(void)
{
	char	solution[11];

	solution[10] = '\0';
	ft_solve_ten_queens(solution, 0);
}

int	main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}
