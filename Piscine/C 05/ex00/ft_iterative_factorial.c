/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:27:02 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/02 13:55:49 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	count;
	int	fact;

	count = 1;
	fact = 1;
	
	if (nb < 0)
	return 0;
	while (count <= nb)
	{
		fact = fact * count;
		count++;
	}
	return fact;
}	
