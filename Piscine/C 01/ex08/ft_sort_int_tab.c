/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:08:26 by mdreesen          #+#    #+#             */
/*   Updated: 2023/02/27 13:59:33 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size - 1)
		temp = tab[i];
	if (tab[i] > tab[i + 1])
	{
		temp = tab[i];
		tab[i] = tab[i + 1];
		tab[i + 1] = temp;
		i = 0;
	}
	else
		i++;
}
