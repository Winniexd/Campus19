/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:58:48 by mdreesen          #+#    #+#             */
/*   Updated: 2023/03/02 12:53:44 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr_helper(int i, long long nbr, char *str)
{
	if (nbr == 0)
	{
		write(1, "0", 2);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	i = 0;
	while (nbr > 0)
	{
		str[i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	while (i > 0)
	{
		write(1, &str[--i], 1);
	}
}

void	ft_putnbr(int nb)
{
	char		str[10];
	int			i;
	long long	nbr;

	nbr = nb;
	i = 0;
	ft_putnbr_helper(i, nbr, str);
}
